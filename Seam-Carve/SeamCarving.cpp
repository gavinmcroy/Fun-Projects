//
// Created by Gavin Taylor Mcroy on 12/1/20.
//
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include "SeamCarving.h"
#include "ImageObject.h"
#include "graphics.h"

/* Static Variable Declaration */
bool SeamCarving::show_blurred_image = false;
bool SeamCarving::firstRun = true;
ImageObject *SeamCarving::image = nullptr;
Blur *SeamCarving::blur = nullptr;

std::map<SeamCarving::Node, int> SeamCarving::edgeWeight;
std::vector<SeamCarving::Node> SeamCarving::allNodes;
std::map<SeamCarving::Node, std::vector<SeamCarving::Node>> SeamCarving::neighbors;
std::map<SeamCarving::Node, SeamCarving::Node> SeamCarving::predecessor;


SeamCarving::Node SeamCarving::megaNode;
std::vector<SeamCarving::Node> SeamCarving::megaNodeNeighbors;
/* Static Variable Declaration */

SeamCarving::SeamCarving(ImageObject *imageObject, Blur *blur1) {
    SeamCarving::image = imageObject;
    blur = blur1;
}

void SeamCarving::calculate_seam() {
    resetCache();
    if(firstRun){
        buildMegaNode();
    }

    buildGraph();
    Node lastNode = modifiedBFS(megaNode);
    std::cout<<lastNode.first<<" "<<lastNode.second;
    markPath(megaNode, lastNode);
}

SeamCarving::Node SeamCarving::modifiedBFS(Node &source) {
    for (Node &a: allNodes) {
        edgeWeight[a] = image->getHeight() * image->getWidth();
    }

    std::queue<Node> toVisit;
    toVisit.push(source);
    edgeWeight[source] = 0;

    Node lastVisited;
    while (!toVisit.empty()) {
        Node x = toVisit.front();
        lastVisited = x;
        toVisit.pop();
        for (const Node &n : neighbors[x]) {
            if (edgeWeight[x] + image->getPixel(x.first,x.second).r < edgeWeight[n]/* distance[n] == (image->getHeight() * image->getWidth())*/) {
                edgeWeight[n] = image->getPixel(x.first,x.second).r + edgeWeight[x];
                predecessor[n] = x;
                toVisit.push(n);
            }
        }
    }
    return lastVisited;
}


void SeamCarving::buildGraph() {
    Node currentPixel;
    std::pair<Node, Node> temporaryPair;
    Node edge;
    allNodes.reserve(image->getWidth()*image->getHeight() / 2);
    for (int x = 0; x < image->getWidth(); x++) {
        for (int y = 0; y < image->getHeight(); y++) {
            /* Index of every pixel in the image */
            allNodes.emplace_back(x, y);
        }
    }
    for (int x = 0; x < image->getWidth(); x++) {
        for (int y = 0; y < image->getHeight(); y++) {
            int intensity = 0;
            neighbors[currentPixel].reserve(3);
            currentPixel = Node(x, y);
            if (y + 1 < image->getHeight() && x - 1 >= 0) {
                neighbors[currentPixel].emplace_back(x - 1, y + 1);
                intensity = image->getPixel(x - 1, y + 1).r;
                edge = Node(x - 1, y + 1);
                edgeWeight[edge] = intensity;
            }
            if (y + 1 < image->getHeight() && x + 1 < image->getWidth()) {
                neighbors[currentPixel].emplace_back(x + 1, y + 1);
                intensity = image->getPixel(x + 1, y + 1).r;
                edge = Node(x + 1, y + 1);
                edgeWeight[edge] = intensity;
            }

            if (y + 1 < image->getHeight()) {
                neighbors[currentPixel].emplace_back(x, y + 1);
                intensity = image->getPixel(x, y + 1).r;
                edge = Node(x, y + 1);
                edgeWeight[edge] = intensity;
            }
        }
    }
}

void SeamCarving::buildMegaNode() {
    megaNode = Node(-1, -1);
    megaNodeNeighbors.reserve(image->getWidth());
    for (int i = 0; i < image->getWidth(); i++) {
        megaNodeNeighbors.emplace_back(i, 0);
    }
    neighbors.insert(make_pair(megaNode, megaNodeNeighbors));
}

void SeamCarving::resetCache() {
    predecessor.clear();
    neighbors.clear();
    edgeWeight.clear();

}

//SeamCarving::Node SeamCarving::dijkstraAlg(Node &source) {
//    Node x;
//    std::map<Node, bool> visited;
//    for (Node &a : allNodes) {
//        distance[a] = 999999999;
//    }
//    distance[source] = 0;
//    std::priority_queue<pin, std::vector<pin>, std::greater<pin>> toVisit;
//    toVisit.push(std::make_pair(0, source));
//
//    while (!toVisit.empty()) {
//        x = toVisit.top().second;
//        toVisit.pop();
//        if (visited[x]) {
//            continue;
//        }
//        visited[x] = true;
//        if (x.second == image->getHeight() - 1) {
//            return x;
//        }
//        for (Node n : seamMap[x]) {
//            int weight = edgeWeight[std::make_pair(x, n)];
//            if (distance[x] + weight < distance[n]) {
//                distance[n] = distance[x] + weight;
//                predecessor[n] = x;
//                toVisit.push(std::make_pair(distance[n], n));
//            }
//        }
//    }
//    std::cout << "Made it to end" << std::endl;
//    return x;
//}

bool SeamCarving::seam_exists() {
    for (int x = 0; x < image->getWidth(); x++) if (image->getPixel(x, 0) == image->red) return true;
    return false;
}

void SeamCarving::remove_seam() {
    std::cout << "Removing seam to decrease width to " << image->getWidth() - 1 << "\n";
    for (int y = 0; y < SeamCarving::image->getHeight(); y++) {
        int where_red = -1;
        for (int x = 0; x < SeamCarving::image->getWidth(); x++)
            if (SeamCarving::image->getPixel(x, y) == SeamCarving::image->red)
                if (where_red != -1) {
                    std::cout << "Error: row " << y << " has >1 red pixel set\n";
                    exit(0);
                } else where_red = x;

        if (where_red == -1) {
            std::cout << "Error: row " << y << " has 0 red pixels set\n";
             exit(0);
        }
        for (int x = where_red; x < SeamCarving::image->getWidth() - 1; x++)
            SeamCarving::image->getPixel(x, y) = SeamCarving::image->getPixel(x + 1, y);
    }

    SeamCarving::image->carveImage();
    blur->calculateBlur();
}

void SeamCarving::keyhandler(int key) {
    if (key == 'q') exit(0);

    // Toggle showing blurred image (off-white pixels)
    if (key == 'b') {
        show_blurred_image = !show_blurred_image;
    }


    // Find and remove one seam
    if (key == 's' && !seam_exists()) calculate_seam();

    // Find and remove 2...9 seams
    if ((key >= '2' && key <= '9') && !seam_exists())
        for (int i = 0; i < key - '0'; i++) {
            calculate_seam();
            remove_seam();
        }
}

void SeamCarving::render() {
    // mode is toggled on
    for (int x = 0; x < image->getWidth(); x++)
        for (int y = 0; y < image->getHeight(); y++) {
            ImageObject::Pixel p = image->getPixel(x, y);
            if (show_blurred_image || p == image->white || p == image->red) {
                set_color(p.r, p.g, p.b);
                draw_pixel(x, y);
            }
        }
    // Fill in empty space at right from shrinking the image with blue
    set_color(0, 0, 255);
    for (int x = SeamCarving::image->getWidth(); x < 800; x++)
        draw_line(x, 0, x, image->getHeight() - 1);
}

bool SeamCarving::timer(int msec) {
    static int cumulative = 0;
    static bool found_seam = false;
    cumulative += msec;
    if (cumulative > 1000) {
        cumulative -= 1000;
        if (seam_exists()) {
            if (found_seam) {
                remove_seam();
                found_seam = false;
                return true;
            }
            found_seam = true;
        }
    }
    return false;
}

void SeamCarving::markPath(Node x, Node y) {
    if (x != y) {
        markPath(x, predecessor[y]);
        image->getPixel(y.first, y.second) = image->red;
    }
}

