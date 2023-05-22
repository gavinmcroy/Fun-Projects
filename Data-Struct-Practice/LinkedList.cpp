//
// Created by Gavin T McRoy on 5/21/2023.
//

#include "LinkedList.h"

LinkedList::Node *LinkedList::insert(int value) {
    Node * node = new Node(value);

    if(!root){
        root = node;
        return root;
    }

    return nullptr;
}

LinkedList::Node *LinkedList::remove() {
    return nullptr;
}

LinkedList::Node *LinkedList::size() {
    return nullptr;
}
