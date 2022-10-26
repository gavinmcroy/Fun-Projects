#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middleNode(ListNode *head);

int main() {
    ListNode *head = new ListNode(1);
    ListNode *pointer = head;
    for (int i = 0; i < 4; i++) {
        pointer->next = new ListNode(i + 2);
        pointer = pointer->next;
    }

    ListNode *temp = middleNode(head);
    return 0;
}

ListNode *middleNode(ListNode *head) {
    int size = 0;
    int location = 0;
    int incrementer = 1;
    /* List is of unknown size */
    for (ListNode *start = head; start != nullptr; start = start->next) {
        size++;
    }
    /* If even it needs to be the second element, and odd needs to be rounded up */
    location = (size / 2) + 1;
    for (ListNode *start = head; start != nullptr; start = start->next) {
        if (incrementer == location) {
            std::cout << incrementer;
            return start;
        }
        incrementer++;
    }
    return nullptr;
}