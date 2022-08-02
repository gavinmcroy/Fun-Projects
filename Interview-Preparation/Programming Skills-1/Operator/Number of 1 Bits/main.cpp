#include <iostream>

int hammingWeight(uint32_t n);

int main() {
    std::cout << hammingWeight(11) << std::endl;
}

int hammingWeight(uint32_t n) {
    int hammingWeight = 0;
    for (int i = 0; i < 32; i++) {
        if (n & (1 << i)) {
            hammingWeight++;
        }
    }
    return hammingWeight;
}
