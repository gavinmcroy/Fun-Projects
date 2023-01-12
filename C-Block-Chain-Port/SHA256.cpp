//
// Created by Gavin Taylor Mcroy on 1/10/23.
//

#include "SHA256.h"

#include <utility>
#include <vector>

unsigned int SHA256::rightShift(uint32_t in, uint32_t rotateAmount) {
    const uint32_t INT_BITS = 32;
    return (in >> rotateAmount) | (in << (INT_BITS - rotateAmount));

}

std::string SHA256::sha256(std::string &input) {
    debug = true;
    /* how many bits is our string */
    uint64_t size = input.size() * 8;
    std::vector<uint8_t> preProcess;
    /* preProcess word: fractional parts of the square roots of the first 8 primes */
    const uint32_t H0 = 0x6a09e667;
    const uint32_t H1 = 0xbb67ae85;
    const uint32_t H2 = 0x3c6ef372;
    const uint32_t H3 = 0xa54ff53a;
    const uint32_t H4 = 0x510e527f;
    const uint32_t H5 = 0x9b05688c;
    const uint32_t H6 = 0x1f83d9ab;
    const uint32_t H7 = 0x5be0cd19;

    /* first 32 bits of the fractional parts of the cube root of the first 2-311 prime */
    std::vector<uint32_t> roundConstants = {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
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

    /* Convert input to unsigned char */
    for (int i = 0; i < input.size(); i++) {
        auto val = (uint8_t) input[i];
        preProcess.push_back(val);
    }

    /* Beginning of pre-processing: 128 is the same as adding 1 to the end padded with 0s */
    uint8_t temp = 128;
    preProcess.push_back(temp);

    /* fill in rest of the space with 0's. TODO message size is limited right now to 448 bits */
    while (preProcess.size() * 8 < (512 - 64)) {
        preProcess.push_back(0);
    }

    /* TODO This could be a bug, but I am manually changing endianness of final value */
    uint64_t test = size;
    test = _byteswap_uint64(size);
    auto *p = (uint8_t *) &test;
    for (int i = 0; i < 8; i++) {
        preProcess.push_back(*p);
        p += 1;
    }

    if (debug) {
        std::cout << " PRE PROCESS " << std::endl;
        for (int i = 0; i < preProcess.size(); i++) {
            std::cout << "BYTE: " << i << " " << std::bitset<8>(preProcess[i]).to_string() << " NUMBER: "
                      << preProcess[i] << std::endl;
        }
        std::cout << "CREATION OF MESSAGE SCHEDULE: " << std::endl;
    }

    if ((preProcess.size() * 8) % 512 != 0) {
        std::cerr << "Error: chunk is not of size 512";
        exit(1);
    }

    /* TODO error in the message creation: Create Message Schedule */
    std::vector<uint32_t> w;
    int increment = 0;
    for (int i = 0; i < 64; i++) {
        /* We are within our 512 bit junk (64 byte) */
        if (increment < preProcess.size()) {
            uint32_t word;
            auto *sliceIntoWord = (uint8_t *) &word;
            for (int j = 0; j < 4; j++) {
                *sliceIntoWord = (uint8_t) preProcess[j + increment];
                sliceIntoWord++;
            }

            word = _byteswap_ulong(word);

            if (debug) {
                std::string temp = std::bitset<32>(word).to_string();
                std::cout << "BITS " << temp.size() << " : " << temp << " NUMBER: " << word << std::endl;
            }

            w.push_back(word);
            increment += 4;
        } else {
            w.push_back(0);
        }
    }

    /* Modify 0 indices at the end of the array */
    for (int i = 16; i < 64; i++) {
//        s0 = (w[i-15] rightrotate 7) xor (w[i-15] rightrotate 18) xor (w[i-15] rightshift 3)
//        s1 = (w[i- 2] rightrotate 17) xor (w[i- 2] rightrotate 19) xor (w[i- 2] rightshift 10)
//        w[i] = w[i-16] + s0 + w[i-7] + s1
        uint32_t s0 = (rightShift(w[i - 15], 7)) ^ (rightShift(w[i - 15], 18))
                      ^ rightShift(w[i - 15], 3);
        //s0 = _byteswap_ulong(s0);
        uint32_t s1 = (rightShift(w[i - 2], 17)) ^ (rightShift(w[i - 2], 19))
                      ^ rightShift(w[i - 2], 10);
        //s1 = _byteswap_ulong(s1);
        w[i] = w[i - 16] + s0 + w[i - 7] + s1;

//        unsigned int test = _byteswap_ulong(w[i]);
//        unsigned int duplicate = w[i];
//        std::string binary = std::bitset<32>(w[i]).to_string();
//        std::string binary2 = std::bitset<32>(s0).to_string();
//        std::cout << binary << std::endl;
//        std::cout << binary2 << std::endl;
        break;
    }
    return " ";
}


