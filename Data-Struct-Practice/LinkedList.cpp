//
// Created by Gavin T McRoy on 5/21/2023.
//

#include "LinkedList.h"

void LinkedList::printValues() {
    for (Node *i = root; i != nullptr; i = i->next) {
        std::cout << i->val << " ";
    }
}

LinkedList::Node *LinkedList::insert(int value) {
    Node *newNode = new Node(value);
    newNode->val = value;

    if (!root) {
        root = newNode;
        return root;
    }

    for (Node *i = root; i != nullptr; i = i->next) {
        /* Insert at end */
        if (i->next == nullptr) {
            i->next = newNode;
            break;
        }
    }

    return newNode;
}

LinkedList::Node *LinkedList::remove(int index) {
    int count = 0;
    Node *previous = root;
    for (Node *i = root; i != nullptr; i = i->next) {
        if (index == count) {
            std::cout << previous->val << std::endl;
            std::cout << i->val << std::endl;
            break;
        }

        /* Start after 1st element */
        if(count != 0){
            previous = previous->next;
        }

        count++;
    }
    return nullptr;
}

int LinkedList::size() {
    int count = 0;
    for (Node *i = root; i != nullptr; i = i->next) {
        count++;
    }
    return count;
}
