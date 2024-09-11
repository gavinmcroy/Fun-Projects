#include <iostream>

int doMath(int val);

int main() {
    std::cout << "Hello, World!" << std::endl;
   // std:: cout<< doMath(12) << std::endl;
   doMath(30);
    return 0;
}

int doMath(int val){
    if(val == 0){
        return val;
    }
    std::cout<<val<<std::endl;
    val--;
    return doMath(val);
}