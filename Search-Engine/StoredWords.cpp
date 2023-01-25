//
// Created by Gavin Taylor Mcroy on 1/20/23.
//

#include "StoredWords.h"

std::vector<StoredWords::Word> &StoredWords::getWords(){
    return words;
}

StoredWords::StoredWords(int alloc) {
    words.reserve(alloc);
}