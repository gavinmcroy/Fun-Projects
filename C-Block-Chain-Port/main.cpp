#include <iostream>
#include <bitset>
#include <chrono>
#include "SHA256.h"

using namespace std::chrono;

void timing();

int main() {



    return 0;
}

void timing() {
    SHA256 sha256{};
    std::string val2 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    std::string val = "A long text A long text A long text A long text A long text "
                      "A long text A long text A long text A long text A long text A "
                      "long text A long text A long text A long text A long text A long "
                      "text A long text A long text A long text A long text A long text A "
                      "long text A long text A long text A long text A long text A long text A "
                      "long text A long text A long text A long text A long text A long text A "
                      "long text A long text A long text A long text A long text A long text A "
                      "long text A long text A long text A long text A long text A long text A "
                      "long text A long text A long text ";

    auto start = high_resolution_clock::now();
    std::string hash = sha256.sha256(val2);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "TIME: " << duration.count() << std::endl;
    std::cout << "HASH: " << hash << std::endl;
}
