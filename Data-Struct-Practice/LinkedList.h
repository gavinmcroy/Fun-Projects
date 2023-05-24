//
// Created by Gavin T McRoy on 5/21/2023.
//

#ifndef DATA_STRUCT_PRACTICE_LINKEDLIST_H
#define DATA_STRUCT_PRACTICE_LINKEDLIST_H

#include <iostream>


class LinkedList {
private:
    typedef struct Node {
        int val;
        Node *next;

        Node(int val) {
            val = val;
            next = nullptr;
        }

        Node() {
            val = 0;
            next = nullptr;
        }
    } Node;

    Node *root;

public:

    LinkedList() {
        root = nullptr;
    }

    void printValues();

    Node *insert(int value);

    /* 0 Based Index */
    Node *remove(int index);

    int size();


};


#endif //DATA_STRUCT_PRACTICE_LINKEDLIST_H
