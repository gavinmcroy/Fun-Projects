#include <iostream>

#include "SHA256.h"

int main() {
    SHA256 sha256;
    std::string val = "hello world";
    std::string binary = sha256.sha256(val);
    std::cout<<binary<<std::endl;

    return 0;
}
