//
// Created by Gavin Taylor Mcroy on 9/27/2020 AD.
//

#include "StoredWords.h"

std::vector<StoredWords::Word> &StoredWords::getWords(){
    return words;
}

StoredWords::StoredWords(int alloc) {
    words.reserve(alloc);
}