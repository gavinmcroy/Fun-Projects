//
// Created by Gavin T McRoy on 5/21/2023.
//

#ifndef DATA_STRUCT_PRACTICE_LINKEDLIST_H
#define DATA_STRUCT_PRACTICE_LINKEDLIST_H


class LinkedList {
private:
    typedef struct Node {
        int val;
        Node *node;

        Node(int val) {
            val = val;
            node = nullptr;
        }

        Node() {
            val = 0;
            node = nullptr;
        }
    } Node;

    Node *root;

public:

    LinkedList() {
        root = nullptr;
    }

    Node *insert(int value);

    Node *remove();

    Node *size();


};


#endif //DATA_STRUCT_PRACTICE_LINKEDLIST_H
