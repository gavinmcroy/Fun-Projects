//
// Created by Gavin Taylor Mcroy on 9/26/2020 AD.
//

#ifndef PROJECT_1_STOREDWEBPAGES_H
#define PROJECT_1_STOREDWEBPAGES_H

#include<string>
#include<utility>
#include<vector>

class StoredWebPages {

/* PAGE (IS THE WEBPAGE)
 * LINK (IS THE HYPER LINK INSIDE THE WEBPAGE)
 * Then there are words on the page
 * */
public:
    struct Webpage {
        std::string url;                /* https://www.clemson.edu */
        int numLinks;                   /* Number of outgoing links on the page */
        int numWords;                   /* Number of words on the page */
        std::vector<int> links;         /* Array of page IDs to which this page links */
        std::vector<std::string> words; /* Array of all words on the page */
        double weight;                  /* Importance of the page, using PageRank algorithm */
        double newWeight;
        bool isDuplicatePrint;

        Webpage(std::string url, int numLinks, int numWords, std::vector<int> links,
                std::vector<std::string> words) {
            this->url = std::move(url);
            this->numLinks = numLinks;
            this->numWords = numWords;
            this->links = std::move(links);
            this->words = std::move(words);
            this->weight = 1;
            /*TEST */
            this->words.reserve(1000);
            isDuplicatePrint = false;
        }
    };

    std::vector<Webpage> &getWebPages();

    StoredWebPages(int alloc);

private:
    std::vector<Webpage> pages; /* Array of all webpages */
};


#endif //PROJECT_1_STOREDWEBPAGES_H
