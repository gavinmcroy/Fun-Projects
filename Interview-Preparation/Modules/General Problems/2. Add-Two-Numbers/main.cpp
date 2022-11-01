#include <iostream>

/*
 * You are given two non-empty linked lists representing
 * two non-negative integers. The digits are stored in reverse order,
 * and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero,
except the number 0 itself.
 */

typedef struct ListNode {
    int val;
    ListNode *next;

    ListNode(int value, ListNode *nextPointer) {
        val = value;
        next = nextPointer;
    }

} ListNode;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

void add(ListNode *head, int x);

void printList(ListNode *head);

int main() {
    auto *head = new ListNode(2, nullptr);
    auto *head2 = new ListNode(5, nullptr);

    /* First List */
    add(head, 4);
    add(head, 3);

    /* Second List */
    add(head2, 6);
    add(head2, 4);


    
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


void add(ListNode *head, int x) {
    ListNode *start;
    for (start = head; start->next != nullptr; start = start->next) {

    }
    start->next = new ListNode(x, nullptr);
}

void printList(ListNode *head) {
    for (ListNode *start = head; start != nullptr; start = start->next) {
        std::cout << start->val << std::endl;
    }
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

}


