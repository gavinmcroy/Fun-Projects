//
// Created by Gavin T McRoy on 10/30/2022.
//

#ifndef IMPLEMENT_QUEUE_STACK_MYQUEUE_H
#define IMPLEMENT_QUEUE_STACK_MYQUEUE_H

#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class MyQueue {

    stack<int> stack1;


public:

    MyQueue() {

    }

    void push(int x) {
        if (stack1.empty()) {
            stack1.push(x);
        } else {
            stack1.push(x);
        }
    }


    int pop() {
        stack<int> temp = stack1;
        if (stack1.empty()) {
            return -1;
        }

        /* Duplicate stack1 into vector */
        std::vector<int> myVec;
        while (!stack1.empty()) {
            int val = stack1.top();
            stack1.pop();
            myVec.push_back(val);
        }
        /* Reverse the structure to turn it into a queue */
        std::reverse(myVec.begin(), myVec.end());
        int top = myVec[0];
        myVec.erase(myVec.begin());
        //std::reverse(myVec.begin(),myVec.end());
        for (int i = 0; i < myVec.size(); i++) {
            stack1.push(myVec[i]);
        }
        return top;
    }

    int peek() {
        std::stack<int> temp = stack1;
        std::vector<int> myVec;
        while (!stack1.empty()) {
            int val = stack1.top();
            stack1.pop();
            myVec.push_back(val);
        }

        std::reverse(myVec.begin(), myVec.end());
        int val = myVec[0];
        stack1 = temp;
        return val;
    }

    bool empty() {
        if (stack1.empty()) {
            return true;
        } else {
            return false;
        }
    }
};


#endif //IMPLEMENT_QUEUE_STACK_MYQUEUE_H
