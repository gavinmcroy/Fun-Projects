#include <iostream>

#include "SHA256.h"
#include <bitset>

//implemented based on https://blog.boot.dev/cryptography/how-sha-2-works-step-by-step-sha-256/#how-does-the-sha-256-algorithm-work

int main() {
    SHA256 sha256{};
    std::string val = "hello world";
    std::string binary = sha256.sha256(val);
//    std::bitset<32> value(21);
//    value[31] = 1;
//    std::cout<<value.to_string()<<std::endl;
//    for(int i = 0; i < 32; i++){
//        std::cout<<value[i];
//    }
//    std::cout<<binary<<std::endl;

    return 0;
}
