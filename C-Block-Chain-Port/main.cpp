#include <iostream>

#include "SHA256.h"
#include <bitset>

//implemented based on https://blog.boot.dev/cryptography/how-sha-2-works-step-by-step-sha-256/#how-does-the-sha-256-algorithm-work

int main() {
    SHA256 sha256{};
    std::string val2 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    std::string val = "A long text A long text A long text A long text A long text "
                      "A long text A long text A long text A long text A long text A "
                      "long text A long text A long text A long text A long text A long "
                      "text A long text A long text A long text A long text A long text A "
                      "long text A long text A long text A long text A long text A long text A "
                      "long text A long text A long text A long text A long text A long text A "
                      "long text A long text A long text A long text A long text A long text A "
                      "long text A long text A long text A long text A long text A long text A "
                      "long text A long text A long text ";
    std::cout<<val2.size()<<std::endl;
    std::string binary = sha256.sha256(val2);
    std::cout << binary << std::endl;
    return 0;
}
