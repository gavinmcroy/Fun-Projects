#include <iostream>

#include "MyQueue.h"

int main() {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    std::cout<<queue.peek()<<std::endl;
    std::cout << queue.pop() << std::endl;

    std::cout<<queue.empty()<<std::endl;

   // std::cout << queue.empty();
    return 0;
}
