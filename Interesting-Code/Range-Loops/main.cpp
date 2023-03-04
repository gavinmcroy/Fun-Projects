#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    int numbers[] = {3,6,8};

    for(int &val: numbers){
        std::cout<<val<<std::endl;
        std::cin>>val;
    }

    for(int val: numbers){
        std::cout<<val<<std::endl;
    }
    return 0;
}
