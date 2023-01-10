//
// Created by Gavin Taylor Mcroy on 1/10/23.
//

#include "SHA256.h"

#include <utility>
#include <vector>

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
    /* Operation specific */
    std::vector<std::string> messageSchedule;
    /* useful constants */
    const int MULTIPLE = 512;
    const int STRING_BIT_SIZE = 64;
    /* hash value: fractional parts of the square roots of the first 8 primes */
    const int H0 = 0x6a09e667;
    const int H1 = 0xbb67ae85;
    const int H2 = 0x3c6ef372;
    const int H3 = 0xa54ff53a;
    const int H4 = 0x510e527f;
    const int H5 = 0x9b05688c;
    const int H6 = 0x1f83d9ab;
    const int H7 = 0x5be0cd19;

    /* first 32 bits of the fractional parts of the cube root of the first 2-311 prime */
    std::vector<unsigned int> roundConstants = {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
                                                0x923f82a4,
                                                0xab1c5ed5,
                                                0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe,
                                                0x9bdc06a7, 0xc19bf174,
                                                0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa,
                                                0x5cb0a9dc, 0x76f988da,
                                                0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
                                                0x06ca6351, 0x14292967,
                                                0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb,
                                                0x81c2c92e, 0x92722c85,
                                                0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624,
                                                0xf40e3585, 0x106aa070,
                                                0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
                                                0x5b9cca4f, 0x682e6ff3,
                                                0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb,
                                                0xbef9a3f7, 0xc67178f2};

    /* Pre-processing */
    std::string zerosToAppend;
    std::string hash = convertStringToBinary(input);
    std::string originalSizeInBinary = convertDigitToBinary(hash.size());
    hash += "1";

    /* Save 64 bits for integer at the end which is length of binary string */
    const int PADDING = MULTIPLE - STRING_BIT_SIZE;
    /* data must a multiple of 512 so append 0's to allow it to be */
    while (hash.size() % PADDING != 0) {
        hash += "0";
    }

    /* fill empty space with 0's until there is 64 bits */
    for (int i = originalSizeInBinary.size(); i < 64; i++) {
        zerosToAppend.append("0");
    }
    zerosToAppend += originalSizeInBinary;

    if (zerosToAppend.size() != 64) {
        std::cerr << "Fatal error: in converting size to binary ";
    }
    if ((zerosToAppend.size() + hash.size()) % 512 != 0) {
        std::cerr << "Fatal error: hash is not a multiple of 512";
    }
    hash += zerosToAppend;


    /* Create Message Schedule */
    int tempCounter = 0;
    for (int i = 0; i < 64; i++) {
        std::string word;
        for (int j = 0; j < 32; j++) {
            /* since hash size is a multiple of 512 this condition should hit when j == 0 */
            if (tempCounter > hash.size()) {
                word = "00000000000000000000000000000000";
                break;
            } else {
                word += hash[tempCounter];
                tempCounter++;
            }
        }
        messageSchedule.emplace_back(word);
    }

    /* Modify our 0'd out indices so if our hash is 512. 512 / 32 = 16, the beginning of the 0 filled words */
    for (int i = hash.size() / 32; i < 64; i++) {
       // unsigned int s0 = messageSchedule[i - 15]
    }


    return " ";
}

