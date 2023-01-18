//
// Created by Gavin T McRoy on 1/16/2023.
//

#ifndef C_BLOCK_CHAIN_PORT_BLOCKCHAIN_H
#define C_BLOCK_CHAIN_PORT_BLOCKCHAIN_H

#include <map>
#include <vector>
#include <fstream>

class Blockchain {
private:
    typedef std::string Account;

    /* TODO Need to assign these values */
    typedef struct Tx {
        Account from;
        Account to;
        unsigned int value;
        std::string data;
    } Tx;

    typedef struct State {
        std::map<Account, unsigned int> balances;
        std::vector<Tx> txMemPool;
        std::fstream dbFile;
    } State;

    State * loadGenesis(std::string &filePath);

public:
    State * newStateFromDisc();

    bool isReward(Tx t);
};


#endif //C_BLOCK_CHAIN_PORT_BLOCKCHAIN_H
