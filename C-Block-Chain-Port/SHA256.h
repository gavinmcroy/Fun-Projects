//
// Created by Gavin Taylor Mcroy on 1/10/23.
//

#ifndef C_BLOCK_CHAIN_PORT_SHA256_H
#define C_BLOCK_CHAIN_PORT_SHA256_H

#include <string>
#include <iostream>

class SHA256 {
private:
    //std::string convertDigitToBinary(unsigned int digit);

public:
    //std::string convertStringToBinary(std::string &input);

    std::string sha256(std::string &input);

};


#endif //C_BLOCK_CHAIN_PORT_SHA256_H
