//
// Created by Gavin T McRoy on 1/16/2023.
//

#include "Blockchain.h"

Blockchain::State * Blockchain::loadGenesis(std::string & filePath){
    /* TODO HERE */
    return nullptr;
}

Blockchain::State *Blockchain::newStateFromDisc() {
    std::string input = "Genesis.json";
    State * gen = loadGenesis(input);

    return nullptr;
}

bool Blockchain::isReward(Blockchain::Tx t) {
    return t.data == "reward";
}
