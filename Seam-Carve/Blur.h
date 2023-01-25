//
// Created by Gavin McRoy on 11/25/2020.
//
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include "ImageObject.h"

#ifndef PROJECT_4_BLUR_1_BLUR_H
#define PROJECT_4_BLUR_1_BLUR_H


class Blur {
private:
    ImageObject *image;
    typedef std::pair<int, int> Node;

    Node megaNode;

    std::vector<Node> allWhitePixels;
    std::vector<Node> allNodes;
    std::map<Node, int> distance;
    std::map<Node, Node> predecessor;
    std::map<Node, std::vector<Node>> neighbors;


    void buildGraph();

    void buildMegaNode();

    void findEveryWhitePixel();

    void breadthFirstSearch(const Node &source);

public:
    Blur(ImageObject *imageObject);

    void calculateBlur();

};


#endif //PROJECT_4_BLUR_1_BLUR_H
