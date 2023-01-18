//
// Created by Gavin Taylor Mcroy on 9/27/2020 AD.
//

#ifndef PROJECT_1_STOREDWORDS_H
#define PROJECT_1_STOREDWORDS_H

#include <string>
#include <utility>
#include <vector>

class StoredWords {

public:
    struct Word {
        std::string text;
        int numPages;
        std::vector<int> pages;

        Word(std::string text, int numPages, std::vector<int> pages) {
            this->text = std::move(text);
            this->numPages = numPages;
            this->pages = std::move(pages);
        }
        explicit Word(std::string text) {
            this->text = std::move(text);
            this->numPages = 0;
        }
    };

    explicit StoredWords(int alloc);

    std::vector<Word> &getWords();

private:
    std::vector<Word> words;
};


#endif //PROJECT_1_STOREDWORDS_H
