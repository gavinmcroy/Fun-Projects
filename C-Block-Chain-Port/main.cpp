#include <iostream>
#include <bitset>
#include <chrono>
#include "SHA256.h"

using namespace std::chrono;
//implemented based on https://blog.boot.dev/cryptography/how-sha-2-works-step-by-step-sha-256/#how-does-the-sha-256-algorithm-work

int main() {
    SHA256 sha256{};
    std::string val2 = "===========================================================================================================================";
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
    return 0;
}
