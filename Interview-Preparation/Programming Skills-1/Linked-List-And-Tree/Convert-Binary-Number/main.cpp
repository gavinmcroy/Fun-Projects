#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getDecimalValue(ListNode *head);

int main() {
    auto *head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);
    getDecimalValue(head);

    return 0;
}

int getDecimalValue(ListNode *head) {
    vector<int> temp;
    int answer = 0;
    for (ListNode *start = head; start != nullptr; start = start->next) {
        temp.push_back(start->val);
    }
    int val = temp.size() - 1;
    for (int x: temp) {
        if (x != 0) {
            answer += std::pow(2, val);
        }
        val--;

    }
    return answer;
}


