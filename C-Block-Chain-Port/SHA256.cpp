//
// Created by Gavin Taylor Mcroy on 1/10/23.
//

#include "SHA256.h"

#include <utility>
#include <vector>

std::bitset<32> SHA256::rightRotate(std::bitset<32> in, uint32_t rotateAmount) {
//    const uint32_t INT_BITS = 32;
//    return (in >> rotateAmount) | (in << (INT_BITS - rotateAmount));
//    const uint32_t mask = (CHAR_BIT * sizeof(in) - 1);  // assumes width is a power of 2.
//
//    // assert ( (c<=mask) &&"rotate by type width or more");
//    rotateAmount &= mask;
//    return (in << rotateAmount) | (in >> ((-rotateAmount) & mask));
    return in >> rotateAmount | in << (32 - rotateAmount);

}


std::string SHA256::sha256(std::string &input) {
    debug = false;
    /* how many bits is our string */
    uint64_t size = input.size() * 8;
    if (size > 512) {
        std::cerr << "There is no support for message greater then 512 bits currently " << std::endl;
    }
    std::vector<uint8_t> preProcess;
    std::vector<std::bitset<8>> preProcessNew;
    std::vector<std::bitset<512>> chunk;
    chunk.emplace_back(0);
    /* preProcess word: fractional parts of the square roots of the first 8 primes */
    std::bitset<32> h0 = 0x6a09e667;
    std::bitset<32> h1 = 0xbb67ae85;
    std::bitset<32> h2 = 0x3c6ef372;
    std::bitset<32> h3 = 0xa54ff53a;
    std::bitset<32> h4 = 0x510e527f;
    std::bitset<32> h5 = 0x9b05688c;
    std::bitset<32> h6 = 0x1f83d9ab;
    std::bitset<32> h7 = 0x5be0cd19;

    /* first 32 bits of the fractional parts of the cube root of the first 2-311 prime */
    std::vector<std::bitset<32>> k = {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
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

    /*  Beginning of Pre-processing stage */
    int iterator = 0;
    for (int i = 0; i < input.size(); i++) {
        auto temp = (uint8_t) input[i];
        std::bitset<8> bitValue(temp);
        /* Bits will be backwards if done 0-size, must be copied in reverse */
        for (int j = 7; j >= 0; j--) {
            chunk[0][iterator] = bitValue[j];
            iterator++;
        }
    }
    /* Add single bit */
    chunk[0].set(iterator, true);

    /* Append 64 Bits to the end in big endian format */
    std::bitset<64> endingInt(size);
    int tempIter = endingInt.size() - 1;
    for (int i = chunk[0].size() - 64; i < chunk[0].size(); i++) {
        if (tempIter < 0) {
            break;
        }
        chunk[0][i] = endingInt[tempIter];
        tempIter--;
    }

    /* Our bits are actually backwards, so we go ahead and reverse them */
    int tempIncr = chunk[0].size() - 1;
    std::bitset<512> temp;
    for (int i = 0; i < 512; i++) {
        temp[tempIncr] = chunk[0][i];
        tempIncr--;
    }
    chunk[0] = temp;


//    if (debug) {
//        std::cout << chunk[0].to_string() << std::endl;
//    }


    /* Create message schedule */
    const int WORD_SIZE = 32;
    std::vector<std::bitset<WORD_SIZE>> w;
    for (int i = 0; i < chunk.size(); i++) {
        int chunkIter = chunk[0].size() - 1;
        for (int j = 0; j < chunk[i].size() / WORD_SIZE; j++) {
            std::bitset<WORD_SIZE> word;
            for (int z = word.size() - 1; z >= 0; z--) {
                word[z] = chunk[i][chunkIter];
                chunkIter--;
            }
            w.push_back(word);
        }
        for (int j = 16; j < 64; j++) {
            std::bitset<32> word;
            word.reset();
            w.push_back(word);
        }
        if (w.size() < 64) {
            std::cerr << " Message schedule generated wrong length";
        }

        if (debug) {
            for (int j = 0; j < w.size(); j++) {
                std::cout << w[j].to_string() << std::endl;
            }
        }


        for (int j = 16; j < 64; j++) {
            std::bitset<32> s0;
            std::bitset<32> s1;
            std::bitset<32> temp1;
            std::bitset<32> temp2;
            std::bitset<32> temp3;

            temp1 = (rightRotate(w[j - 15], 7));
            temp2 = (rightRotate(w[j - 15], 18));
            temp3 = w[j-15] >> 3;

            s0 = temp1 ^ temp2 ^ temp3;
            s1 = (rightRotate(w[j - 2], 17)) ^ (rightRotate(w[j - 2], 19)) ^ (w[j-2]>>10);
            /* TODO this sequence could also be bug prone */
            w[j] = ((w[j - 16]).to_ulong() + s0.to_ulong() + (w[j - 7]).to_ulong() + s1.to_ulong());
            // if (debug) {
            std::cout << "UN-SHIFTED: " << w[1].to_string() << std::endl;
            std::cout << "T1 ANSWER:  " << temp1.to_string() << std::endl;
            std::cout << "T2 ANSWER:  " << temp2.to_string() << std::endl;
            std::cout << "T3 ANSWER:  " << temp3.to_string() << std::endl;

            std::cout << "S0 ANSWER:  " << s0.to_string() << std::endl;
            std::cout << w[j].to_string() << std::endl;
            //  }
            //233049837
            break;
        }

        if (debug) {
            for (int j = 0; j < 64; j++) {
                std::cout << w[j].to_string() << std::endl;
            }
        }

        /* Compression loop */
        std::bitset<32> a = h0, b = h1, c = h2, d = h3, e = h4, f = h5, g = h6, h = h7;
        for (int j = 0; j < 64; j++) {
            std::bitset<32> s1 = rightRotate(e, 6) ^ rightRotate(e, 11) ^ rightRotate(e, 25);
            std::bitset<32> ch = (e & f) ^ ((~e) & g);
            std::bitset<32> temp1 = (h.to_ulong() + s1.to_ulong() + ch.to_ulong() + k[i].to_ulong() + w[i].to_ulong());
            std::bitset<32> s0 = (rightRotate(a, 2)) ^ (rightRotate(a, 13)) ^ rightRotate(a, 22);
            std::bitset<32> maj = (a & b) ^ (a & c) ^ (b & c);
            std::bitset<32> temp2 = s0.to_ulong() + maj.to_ulong();
            h = g;
            g = f;
            f = e;
            e = d.to_ulong() + temp1.to_ulong();
            d = c;
            c = b;
            b = a;
            a = temp1.to_ulong() + temp2.to_ulong();
        }

        h0 = h0.to_ulong() + a.to_ulong();
        h1 = h1.to_ulong() + b.to_ulong();
        h2 = h2.to_ulong() + c.to_ulong();
        h3 = h3.to_ulong() + d.to_ulong();
        h4 = h4.to_ulong() + e.to_ulong();
        h5 = h5.to_ulong() + f.to_ulong();
        h6 = h6.to_ulong() + g.to_ulong();
        h7 = h7.to_ulong() + h.to_ulong();

        std::stringstream stream;
//
        stream << std::hex << h0.to_ulong() << h1.to_ulong() + h2.to_ulong() +
                                               h3.to_ulong() + h4.to_ulong() + h5.to_ulong() + h6.to_ulong() +
                                               h7.to_ulong();
        std::string result(stream.str());
        std::cout << "HASH: " << result << std::endl;
//            std::stringstream stream;
//    h0 = _byteswap_ulong(h0);
//    stream << std::hex << h7;
//    std::string result(stream.str());




        /* TODO This needs to be done */
        //w.clear();
    }




//    /* TODO possible bug in grabbing data. Data must be looked at byte by byte
//     * TODO rather than being casted to a int since that effects original order of bits (endian)
//     * TODO Create Message Schedule */
//    std::vector<uint32_t> w;
//    int increment = 0;
//    for (int i = 0; i < 64; i++) {
//        /* We are within our 512 bit junk (64 byte) */
//        if (increment < preProcess.size()) {
//            uint32_t word;
//            auto *sliceIntoWord = (uint8_t *) &word;
//            for (int j = 0; j < 4; j++) {
//                *sliceIntoWord = (uint8_t) preProcess[j + increment];
//                sliceIntoWord++;
//            }
//            // word = _byteswap_ulong(word);
//
////            if (debug) {
////                std::string stringTemp = std::bitset<32>(word).to_string();
////                std::cout << "BITS " << stringTemp.size() << " : " << stringTemp << " NUMBER: " << word << std::endl;
////            }
//
//            w.push_back(word);
//            increment += 4;
//        } else {
//            w.push_back(0);
//        }
//    }
//
//    /* TODO There is a bug in this part of the SHA-256 Creation */
//    for (int i = 16; i < 64; i++) {
////        s0 = (w[i-15] rightrotate 7) xor (w[i-15] rightrotate 18) xor (w[i-15] rightshift 3)
////        s1 = (w[i- 2] rightrotate 17) xor (w[i- 2] rightrotate 19) xor (w[i- 2] rightshift 10)
////        w[i] = w[i-16] + s0 + w[i-7] + s1
//
//
//        uint32_t s0 = (rightShift(w[i - 15], 7)) ^ (rightRotate(w[i - 15], 18))
//                      ^ rightRotate(w[i - 15], 3);
//
//        uint32_t s1 = (rightRotate(w[i - 2], 17)) ^ (rightShift(w[i - 2], 19))
//                      ^ rightRotate(w[i - 2], 10);
//
//        w[i] = w[i - 16] + s0 + w[i - 7] + s1;
//
//    }
//
//    /* Compression */
//    uint32_t a = h0, b = h1, c = h2, d = h3, e = h4, f = h5, g = h6, h = h7;
//    for (int i = 0; i < 64; i++) {
//        uint32_t s1 = rightShift(e, 6) ^ rightShift(e, 11) ^ rightRotate(e, 25);
//        uint32_t ch = (e & f) ^ ((!e) & g);
//        uint32_t temp1 = h + s1 + ch + k[i] + w[i];
//        uint32_t s0 = rightShift(a, 2) ^ rightShift(a, 13) ^ rightRotate(a, 22);
//        uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
//        uint32_t temp2 = s0 + maj;
//        h = g;
//        g = f;
//        f = e;
//        e = d + temp1;
//        d = c;
//        c = b;
//        b = a;
//        a = temp1 + temp2;
//    }
//
//    h0 += a;
//    h1 += b;
//    h2 += c;
//    h3 += d;
//    h4 += e;
//    h5 += f;
//    h6 += g;
//    h7 += h;
//    std::string answer;
//
//    std::stringstream stream;
//    h0 = _byteswap_ulong(h0);
//    stream << std::hex << h7;
//    std::string result(stream.str());
//    //45a5ddc2
//    //9ed47ddc
//    std::cout << result;
//    return " ";
    return " ";
}


