//
// Created by Gavin Taylor Mcroy on 1/10/23.
//

#include "SHA256.h"
#include <vector>

std::bitset<32> SHA256::rightRotate(std::bitset<32> in, uint32_t rotateAmount) {
    return in >> rotateAmount | in << (32 - rotateAmount);
}

std::string SHA256::sha256(std::string &input) {
    debug = false;
    const int CHUNK_SIZE_BITS = 512;
    const int BYTE_SIZE_BITS = 8;
    const int WORD_SIZE_BITS = 32;
    const int MSG_LENGTH_BITS = 64;

    /* how many bits is our string */
    const uint64_t size = input.size() * BYTE_SIZE_BITS;
    std::vector<std::bitset<BYTE_SIZE_BITS>> dataToBinary;
    std::vector<uint8_t> preProcess;
    std::vector<std::bitset<BYTE_SIZE_BITS>> preProcessNew;
    std::vector<std::bitset<CHUNK_SIZE_BITS>> chunk;

    /* Add the appropriate total of chunks. We need room for a single bit + 64 bits for message length. The extra + 1
     * is just for integer truncation (2/3 filled = 0, when we still need a chunk to allow it to be filled */
    for (int i = 0; i < ((size + MSG_LENGTH_BITS + 1) / CHUNK_SIZE_BITS) + 1; i++) {
        chunk.emplace_back(0);
    }

    if (debug) {
        std::cout << "CHUNK SIZE: " << chunk.size() << std::endl;
    }

    /* preProcess word: fractional parts of the square roots of the first 8 primes */
    std::bitset<WORD_SIZE_BITS> h0 = 0x6a09e667;
    std::bitset<WORD_SIZE_BITS> h1 = 0xbb67ae85;
    std::bitset<WORD_SIZE_BITS> h2 = 0x3c6ef372;
    std::bitset<WORD_SIZE_BITS> h3 = 0xa54ff53a;
    std::bitset<WORD_SIZE_BITS> h4 = 0x510e527f;
    std::bitset<WORD_SIZE_BITS> h5 = 0x9b05688c;
    std::bitset<WORD_SIZE_BITS> h6 = 0x1f83d9ab;
    std::bitset<WORD_SIZE_BITS> h7 = 0x5be0cd19;

    /* first 32 bits of the fractional parts of the cube root of the first 2-311 prime */
    std::vector<std::bitset<WORD_SIZE_BITS>> k = {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b,
                                                  0x59f111f1,
                                                  0x923f82a4,
                                                  0xab1c5ed5,
                                                  0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74,
                                                  0x80deb1fe,
                                                  0x9bdc06a7, 0xc19bf174,
                                                  0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f,
                                                  0x4a7484aa,
                                                  0x5cb0a9dc, 0x76f988da,
                                                  0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3,
                                                  0xd5a79147,
                                                  0x06ca6351, 0x14292967,
                                                  0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354,
                                                  0x766a0abb,
                                                  0x81c2c92e, 0x92722c85,
                                                  0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819,
                                                  0xd6990624,
                                                  0xf40e3585, 0x106aa070,
                                                  0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3,
                                                  0x4ed8aa4a,
                                                  0x5b9cca4f, 0x682e6ff3,
                                                  0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa,
                                                  0xa4506ceb,
                                                  0xbef9a3f7, 0xc67178f2};

    /*  Beginning of Pre-processing stage, convert input into binary, and assign our chunks */
    int currentBit = 0;
    int currentChunk = 0;
    for (int i = 0; i < input.size(); i++) {
        auto temp = (uint8_t) input[i];
        std::bitset<BYTE_SIZE_BITS> bitValue(temp);
        /* Bits will be backwards if done 0-size, must be copied in reverse */
        for (int j = BYTE_SIZE_BITS - 1; j >= 0; j--) {
            /* input.size() can exceed 512, so when it does move to another chunk */
            if (currentBit > CHUNK_SIZE_BITS - 1) {
                currentChunk++;
                currentBit = 0;
                chunk[currentChunk][currentBit] = bitValue[j];
                currentBit++;
            } else {
                chunk[currentChunk][currentBit] = bitValue[j];
                currentBit++;
            }
        }
    }
    /* Add single bit If this current chunk doesn't have the room for it,
     * move it to a new chunk */
    if (currentBit > (CHUNK_SIZE_BITS - BYTE_SIZE_BITS - MSG_LENGTH_BITS)) {
        /* Edge case when the chunk has no room for a 1 to be appended */
        if (currentBit > CHUNK_SIZE_BITS - 8) {
            currentBit = 0;
            currentChunk++;
            chunk[currentChunk].set(currentBit, true);

        }
            /* There is still room for a 1 to be appended towards the end but not enough room for 64 bits */
        else {
            chunk[currentChunk].set(currentBit, true);
            currentChunk++;
        }
    } /* There is enough room for 64 bits plus the one bit */
    else {
        chunk[currentChunk].set(currentBit, true);
    }

    /* Append 64 Bits to the end in big endian format */
    std::bitset<MSG_LENGTH_BITS> msgLength(size);
    int msgLengthIter = msgLength.size() - 1;
    for (int i = CHUNK_SIZE_BITS - 64; i < CHUNK_SIZE_BITS; i++) {
        if (msgLengthIter < 0) {
            break;
        }
        chunk[currentChunk][i] = msgLength[msgLengthIter];
        msgLengthIter--;
    }

    /* Our bits are actually backwards, so we go ahead and reverse them for each chunk */
    for (int i = 0; i < chunk.size(); i++) {
        int tempIncr = CHUNK_SIZE_BITS - 1;
        std::bitset<CHUNK_SIZE_BITS> temp;
        for (int j = 0; j < CHUNK_SIZE_BITS; j++) {
            temp[tempIncr] = chunk[i][j];
            tempIncr--;
        }
        chunk[i] = temp;
    }

    if (debug) {
        for (int i = 0; i < chunk.size(); i++) {
            std::string value = chunk[i].to_string();
            for (int j = 0; j < value.size(); j++) {
                if (j % 8 == 0) {
                    std::cout << std::endl;
                }
                std::cout << value[j];
            }
        }
    }


    for (int i = 0; i < chunk.size(); i++) {
        std::vector<std::bitset<WORD_SIZE_BITS>> w;
        int chunkIter = CHUNK_SIZE_BITS - 1;
        for (int j = 0; j < CHUNK_SIZE_BITS / WORD_SIZE_BITS; j++) {
            std::bitset<WORD_SIZE_BITS> word;
            for (int z = WORD_SIZE_BITS - 1; z >= 0; z--) {
                word[z] = chunk[i][chunkIter];
                chunkIter--;
            }
            w.push_back(word);
        }
        for (int j = 16; j < 64; j++) {
            /* Fill 16-63 with 0's */
            std::bitset<WORD_SIZE_BITS> word;
            word.reset();
            w.push_back(word);
        }
        if (w.size() < 64) {
            std::cerr << " Message schedule generated wrong length";
        }

        if (debug) {
            std::cout << std::endl;
            for (int j = 0; j < w.size(); j++) {
                std::cout << j << " MESSAGE SCHEDULE: " << w[j].to_string() << std::endl;
            }
            std::cout << "END " << i << std::endl;
        }

        /* First round processing */
        for (int j = 16; j < 64; j++) {
            std::bitset<WORD_SIZE_BITS> s0;
            std::bitset<WORD_SIZE_BITS> s1;

            s0 = (rightRotate(w[j - 15], 7)) ^ (rightRotate(w[j - 15], 18)) ^ (w[j - 15] >> 3);
            s1 = (rightRotate(w[j - 2], 17)) ^ (rightRotate(w[j - 2], 19)) ^ (w[j - 2] >> 10);
            w[j] = ((w[j - 16]).to_ulong() + s0.to_ulong() + (w[j - 7]).to_ulong() + s1.to_ulong());
        }

        /* Compression loop */
        std::bitset<WORD_SIZE_BITS> a = h0, b = h1, c = h2, d = h3, e = h4, f = h5, g = h6, h = h7;
        for (int j = 0; j < 64; j++) {
            std::bitset<WORD_SIZE_BITS> s1 = rightRotate(e, 6) ^ rightRotate(e, 11) ^
                                             rightRotate(e, 25);
            std::bitset<WORD_SIZE_BITS> ch = (e & f) ^ ((~e) & g);
            std::bitset<WORD_SIZE_BITS> temp1 = (h.to_ulong() + s1.to_ulong() + ch.to_ulong() + k[j].to_ulong() +
                                                 w[j].to_ulong());
            std::bitset<WORD_SIZE_BITS> s0 = (rightRotate(a, 2)) ^ (rightRotate(a, 13)) ^ rightRotate(a, 22);
            std::bitset<WORD_SIZE_BITS> maj = (a & b) ^ (a & c) ^ (b & c);
            std::bitset<WORD_SIZE_BITS> temp2 = s0.to_ulong() + maj.to_ulong();
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

        if (debug) {
            std::stringstream stream;
            stream << std::hex << h0.to_ulong() << h1.to_ulong() << h2.to_ulong() << h3.to_ulong() << h4.to_ulong()
                   << h5.to_ulong() << h6.to_ulong() << h7.to_ulong();
            std::string result(stream.str());
            std::cout << result << std::endl;
            std::cout << "AFTER COMPRESSION " << std::endl;
            std::cout << "H0 " << h0.to_string() << std::endl;
            std::cout << "H1 " << h1.to_string() << std::endl;
            std::cout << "H2 " << h2.to_string() << std::endl;
            std::cout << "H3 " << h3.to_string() << std::endl;
            std::cout << "H4 " << h4.to_string() << std::endl;
            std::cout << "H5 " << h5.to_string() << std::endl;
            std::cout << "H6 " << h6.to_string() << std::endl;
            std::cout << "H7 " << h7.to_string() << std::endl;

            std::cout << "A " << a.to_string() << std::endl;
            std::cout << "B " << b.to_string() << std::endl;
            std::cout << "C " << c.to_string() << std::endl;
            std::cout << "D " << d.to_string() << std::endl;
            std::cout << "E " << e.to_string() << std::endl;
            std::cout << "F " << f.to_string() << std::endl;
            std::cout << "G " << g.to_string() << std::endl;
            std::cout << "H " << h.to_string() << std::endl;
        }
    }
    std::stringstream stream;
    stream << std::hex << h0.to_ulong() << h1.to_ulong() << h2.to_ulong() << h3.to_ulong() << h4.to_ulong()
           << h5.to_ulong() << h6.to_ulong() << h7.to_ulong();
    std::string result(stream.str());
    return result;
}


