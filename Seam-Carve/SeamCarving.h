//
// Created by Gavin Taylor Mcroy on 12/1/20.
//
#include "ImageObject.h"
#include "Blur.h"

#ifndef PROJECT_4_CLION_SEAMCARVING_H
#define PROJECT_4_CLION_SEAMCARVING_H


class SeamCarving {


public:
    typedef std::pair<int, int> Node;
    typedef std::pair<int,Node> pin;

private:
    static Node megaNode;
    static std::vector<Node> megaNodeNeighbors;
    static bool firstRun;

    static std::map<Node,int> edgeWeight;
    static std::vector<Node> allNodes;
    static std::map<Node, Node> predecessor;
    static std::map<Node, std::vector<Node>> neighbors;

    static bool show_blurred_image;
    static ImageObject *image;
    static Blur *blur;

    static void buildGraph();

    static void buildMegaNode();

    static Node modifiedBFS(Node &source);

    static void resetCache();

    //static Node dijkstraAlg(Node &source);

    static void markPath(Node x,Node y);

public:

    explicit SeamCarving(ImageObject *imageObject, Blur *blur1);

    static void calculate_seam();

    static bool seam_exists();

    static void remove_seam();

    static void keyhandler(int key);

    static void render();

    static bool timer(int msec);


};


#endif //PROJECT_4_CLION_SEAMCARVING_H
