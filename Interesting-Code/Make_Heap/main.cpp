#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    const int MAX_VAL = 10;
    int myInt[] = {4, 12, 3, 89, 34, 78, 31, 10, 18, 46};
    std::vector<int> integers(myInt, myInt + 10);
    std::make_heap(integers.begin(), integers.end(), std::greater<>());
    for (int integer : integers) {
        std::cout << integer << ", ";
    }
    std::cout<<"Erase one "<<std::endl;
    integers.erase(integers.begin());
    std::make_heap(integers.begin(),integers.end(),std::greater<>());
    for (int integer : integers) {
        std::cout << integer << ", ";
    }

    std::cout<<"Erase another" << std::endl;
    integers.erase(integers.begin());
    std::make_heap(integers.begin(),integers.end(),std::greater<>());
    for (int integer : integers) {
        std::cout << integer << ", ";
    }

    std::cout<<"Adding 15"<<std::endl;
    integers.push_back(15);
    std::make_heap(integers.begin(),integers.end(),std::greater<>());
    for (int integer : integers) {
        std::cout << integer << ", ";
    }

    std::priority_queue<int, std::vector<int>, std::greater<> > pq;

    for (int &i : myInt) {
        pq.push(i);
    }


    return 0;
}
