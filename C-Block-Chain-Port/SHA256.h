//
// Created by Gavin Taylor Mcroy on 1/10/23.
//

#ifndef C_BLOCK_CHAIN_PORT_SHA256_H
#define C_BLOCK_CHAIN_PORT_SHA256_H

#include <string>
#include <iostream>
#include <bitset>
#include <iomanip>
#include <intrin.h>

class SHA256 {
private:
    bool debug;

public:
    std::string sha256(std::string &input);

    uint32_t rightShift(uint32_t in, uint32_t rotateAmount);

};


#endif //C_BLOCK_CHAIN_PORT_SHA256_H