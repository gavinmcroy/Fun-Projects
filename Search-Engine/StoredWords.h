//
// Created by Gavin Taylor Mcroy on 1/20/23.
//

#ifndef PROJECT_1_REBUILD_STOREDWORDS_H
#define PROJECT_1_REBUILD_STOREDWORDS_H

#include <string>
#include <utility>
#include <vector>
#include <map>

class StoredWords {
public:
    struct Word {
        std::string text;
        int numPages;
        std::vector<int> pages;
        std::map<std::string,int> frequency;

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


#endif //PROJECT_1_REBUILD_STOREDWORDS_H
