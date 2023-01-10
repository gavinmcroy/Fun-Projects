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
    /* Pre-processing */
    std::string val = convertStringToBinary(input);
    std::string originalSizeBinary = convertDigitToBinary(val.size());
    val += "1";
    int padding = 512 - 64;
    /* data must a multiple of 512 so append 0's to allow it to be
     * Save 64 bits for integer at the end which is length of binary string */
    while (val.size() % padding != 0) {
        val += "0";
    }

    for (int i = originalSizeBinary.size(); i < 64; i++) {

    }

    return " ";
}

