//
// Created by Gavin Taylor Mcroy on 1/10/23.
//

#include "SHA256.h"

#include <utility>

std::string SHA256::convertDigitToBinary(unsigned int digit) {
    std::string binary;
    int start = 128;
    while (start > 0) {
        if (digit < start) {
            binary.append("0");
        } else {
            digit -= start;
            binary.append("1");
        }
        start = start >> 1;
    }
    return binary;
}

std::string SHA256::convertStringToBinary(std::string &input) {
    std::string binary;
    for (int i = 0; i < input.size(); i++) {
        unsigned int val = (int) input[i];
        binary += convertDigitToBinary(val);
    }

    return binary;
}

std::string SHA256::sha256(std::string &input) {
    /* fractional parts of the square roots of the first 8 primes */
    const int H0 = 0x6a09e667;
    const int H1 = 0xbb67ae85;
    const int H2 = 0x3c6ef372;
    const int H3 = 0xa54ff53a;
    const int H4 = 0x510e527f;
    const int H5 = 0x9b05688c;
    const int H6 = 0x1f83d9ab;
    const int H7 = 0x5be0cd19;

    /* Pre-processing */
    std::string hash = convertStringToBinary(input);
    std::string originalSizeInBinary = convertDigitToBinary(hash.size());
    hash += "1";
    int padding = 512 - 64;
    /* data must a multiple of 512 so append 0's to allow it to be
     * Save 64 bits for integer at the end which is length of binary string */
    while (hash.size() % padding != 0) {
        hash += "0";
    }
    std::string zeros;
    for (int i = originalSizeInBinary.size(); i < 64; i++) {
        zeros.append("0");
    }
    zeros += originalSizeInBinary;


    if (zeros.size() != 64) {
        std::cerr << "Fatal error: in converting size to binary ";
    }
    if ((zeros.size() + hash.size()) % 512 != 0) {
        std::cerr << "Fatal error: hash is not a multiple of 512";
    }


    hash += zeros;


    return " ";
}

