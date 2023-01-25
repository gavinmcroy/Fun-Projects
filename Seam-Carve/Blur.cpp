//
// Created by Gavin McRoy on 11/25/2020.
//
#include "Blur.h"

Blur::Blur(ImageObject *imageObject) {
    this->image = imageObject;
    allNodes.reserve((image->getWidth() * image->getHeight()) / 2);
    allWhitePixels.reserve(75000);
}

void Blur::breadthFirstSearch(const Node &source) {
    for (Node &a: allNodes) {
        distance[a] = image->getHeight() * image->getWidth();
    }
    distance[source] = 0;
    std::queue<Node> toVisit;
    toVisit.push(source);

    while (!toVisit.empty()) {
        Node x = toVisit.front();
        toVisit.pop();
        for (const Node &n : neighbors[x]) {
            if (distance[n] == (image->getHeight() * image->getWidth())) {
                distance[n] = 1 + distance[x];
                predecessor[n] = x;
                toVisit.push(n);
            }
        }
    }

}

void Blur::buildGraph() {
    std::vector<Node> tempNeighbors;
    tempNeighbors.reserve(4);
    for (int x = 0; x < image->getWidth(); x++) {
        for (int y = 0; y < image->getHeight(); y++) {
            /* Index of every pixel in the image */
            allNodes.emplace_back(x, y);
        }
    }
    for (int x = 0; x < image->getWidth(); x++) {
        for (int y = 0; y < image->getHeight(); y++) {
            if (x - 1 >= 0) {
                tempNeighbors.emplace_back(x - 1, y);
            }
            if (x + 1 < image->getWidth()) {
                tempNeighbors.emplace_back(x + 1, y);
            }
            if (y - 1 >= 0) {
                tempNeighbors.emplace_back(x, y - 1);
            }
            if (y + 1 < image->getHeight()) {
                tempNeighbors.emplace_back(x, y + 1);
            }
            /* Insert the node and then its neighbors */
            neighbors.insert(std::make_pair(std::make_pair(x, y), tempNeighbors));
            tempNeighbors.clear();
        }
    }
}

void Blur::buildMegaNode() {
    megaNode = std::make_pair(-1, -1);
    findEveryWhitePixel();
    neighbors.insert(std::make_pair(megaNode, allWhitePixels));
}

/* Call print path from every pixel until it finds the nearest white pixel ? */
void Blur::calculateBlur() {
    buildGraph();
    buildMegaNode();
    breadthFirstSearch(megaNode);
    for (int i = 0; i < image->getWidth(); i++) {
        for (int j = 0; j < image->getHeight(); j++) {
            int x = distance[std::make_pair(i, j)];
            int calculation = 255 * std::pow(.9, x - 1);
            image->getPixel(i, j).r = calculation;
            image->getPixel(i, j).g = calculation;
            image->getPixel(i, j).b = calculation;
        }
    }
}


void Blur::findEveryWhitePixel() {
    int tempCount = 0;
    for (int i = 0; i < image->getWidth(); i++) {
        for (int j = 0; j < image->getHeight(); j++) {
            if (image->getPixel(i, j) == image->white) {
                allWhitePixels.emplace_back(i, j);
                tempCount++;
            }
        }
    }
    std::cout << allWhitePixels.at(0).first << " " << allWhitePixels.at(0).second;
}

/* Debug Statement */
//
//int Blur::printShortedPathOnImage(Node x, Node y) {
//    int steps = 0;
//    while (predecessor[y] != x) {
//        //int operation = y.second * width + y.first;
//        Node val = predecessor[y];
//        image->getPixel(y.first, y.second).r = 255;
//        image->getPixel(y.first, y.second).g = 0;
//        image->getPixel(y.first, y.second).b = 0;
//        y = val;
//        steps++;
//    }
//    return steps;
//}
