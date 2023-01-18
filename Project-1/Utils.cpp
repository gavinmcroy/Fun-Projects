#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#include "StoredWebPages.h"
#include "StringIntMap.h"
#include "StoredWords.h"

using namespace std;

/* TEMP */
int tmpAlloc = 180000;
StoredWebPages webPages(25000);
StoredWords storedWords(tmpAlloc);
StringIntMap webPageIntMap;
StringIntMap wordIntMap;
auto *wordOnPage = new StringIntMap;
std::vector<StoredWebPages::Webpage> pages = webPages.getWebPages();
std::vector<StoredWords::Word> everyDistinctWordVec = storedWords.getWords();
/* TEMP */

bool operator<(const StoredWebPages::Webpage &a, const StoredWebPages::Webpage &b) {
    return a.weight < b.weight;
}

/* Returns entire file as one big string, quickly */
string readWebpagesFast(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == nullptr) {
        fprintf(stderr, "Error: can't open %s", filename);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *buff = new char[size + 1];
    buff[size] = 0;
    int dummy_result = fread(buff, size, 1, fp);
    fclose(fp);
    string result(buff);
    delete[] buff;
    return result;
}

/* Some ANSI terminal commands you can print to clear screen and change colors */
string clear_screen = "\e[2J\e[H";
string color_red = "\e[31;40m";
string color_green = "\e[32;40m";
string color_yellow = "\e[33;40m";
string color_blue = "\e[34;40m";
string color_magenta = "\e[35;40m";
string color_cyan = "\e[36;40m";
string color_white = "\e[37;40m";
string color_whiteblue = "\e[37;44m";
string background_blue = "\e[44;1m";
string reset_background = "\e[40m";

/* TODO IMPLEMENT */
void predict(const string &query) {
    cout << color_green << "Next word: '"
         << color_white << "query"
         << color_green << "'\n";

    /* TEST CODE */
}

void processKeystrokes() {
    int ch = 0;
    vector<double> tmpWeight;
    vector<int> tmpPageIndexHolder;
    string query;
    while (ch != '\n') {
        cout << clear_screen << color_green << "Search keyword: "
             << color_white << query
             << color_green << "-\n\n";
        int wordIndex = wordIntMap[query];
        tmpWeight.clear();
        tmpPageIndexHolder.clear();
        cout << color_yellow << "'" << everyDistinctWordVec.at(wordIndex).numPages << color_green << "' pages match"
             << endl;
        /* Store all the page weights of that the desired word links too */
        for (int i = 0; i < everyDistinctWordVec.at(wordIndex).pages.size(); i++) {
            int tmpIndex = everyDistinctWordVec.at(wordIndex).pages.at(i);
            tmpPageIndexHolder.push_back(tmpIndex);
            tmpWeight.push_back(pages.at(tmpIndex).weight);
        }
        sort(tmpWeight.begin(), tmpWeight.end());


        /* Go through every page that links to the word being searched */
        for (int i = 0; i < everyDistinctWordVec.at(wordIndex).numPages; i++) {
            cout << endl;
            int pageIndex = everyDistinctWordVec.at(wordIndex).pages.at(i);
            /* Only want 5 pages to be printed */
            if (i == 5) {
                break;
            }
            /* In case a word only has less than 5 links associated with it  */
            if (i < everyDistinctWordVec.at(wordIndex).numPages) {
                cout << color_white << i + 1 << "." << color_red << " ["
                     << pages.at(pageIndex).weight << "] "
                     << color_white
                     << pages.at(pageIndex).url
                     << endl;
                /* Iterate and find the index of the words on the page itself */
                auto it = std::find(pages.at(pageIndex).words.begin(),
                                    pages.at(pageIndex).words.end(), query);

                if (it != pages.at(pageIndex).words.end()) {
                    int location = it - pages.at(pageIndex).words.begin();
                    /* Put bounds for 5 words surrounding the word being searched */
                    if (location > 5 && location + 5 < pages.at(pageIndex).words.size()) {
                        /* Print the 5 nearest words */
                        for (int j = -5; j <= 5; j++) {
                            /* High light the word being queued */
                            if (j == 0) {
                                cout << background_blue << pages.at(pageIndex).words.at(j + location)
                                     << reset_background
                                     << " ";
                            } else {
                                cout << color_white << pages.at(pageIndex).words.at(j + location) << " ";
                            }
                        }
                    } else {
                        /*TODO Change this to work for texts that are too short to be displayed */
                        cout << "No text provided " << endl;
                    }
                }
            }
            cout << endl;
        }

        predict(query);
        cout << flush;

        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

        if (ch == 8 || ch == 127) { // backspace
            if (query.length() > 0) query = query.substr(0, query.length() - 1);
        } else if (ch != ' ' && ch != '\n') query += ch;
    }
    cout << color_white;

}

int main() {
    const char *filename = "/home/gav/Documents/webpages.txt";
    string readInData;

    cout << color_green << "Reading input..." << endl;
    istringstream webFile(readWebpagesFast(filename));

    /* Insert all PAGES and DISTINCT words into separate hash table */
    {
        int totalWebPages = 0;
        int totalDistinctWords = 0;
        while (webFile >> readInData) {
            if (readInData == "PAGE") {
                webFile >> readInData;
                webPageIntMap.insert(readInData, totalWebPages);
                totalWebPages++;
            } else if (readInData == "LINK ") {
                /* This is catching the hyperlink and just trashing it */
                webFile >> readInData;
            } else {
                /* Store all the DISTINCT words in a map/hash table THAT containing
                 * the words INDEX/POS for the words INSIDE the vector located in StoredWords */
                if (!wordIntMap.find(readInData)) {
                    wordIntMap.insert(readInData, totalDistinctWords);
                    /* This is adding the words to the vector */
                    everyDistinctWordVec.emplace_back(readInData);
                    totalDistinctWords++;
                }
            }
        }
    }
    cout << "Indexing..." << endl;
    /* Reset the file being read */
    webFile.clear();
    webFile.seekg(0);
    /* 26,881 Pages, 184,408 Hyperlinks, 18,896,392 words */
    /* This builds our webpage vector with all appropriate info */
    {
        string url;
        int numLinksOnPageCounter = 0;
        int numWordsOnPageCounter = 0;
        int uniqueWordsOnPageCounter = 0;
        bool firstIteration = true;
        vector<int> links;
        vector<string> wordsOccurringInPage;

        while (webFile >> readInData) {
            if (readInData == "PAGE") {
                if (!firstIteration) {
                    /* Reset all the counters by adding the WebPage + all its data */
                    pages.emplace_back(url, numLinksOnPageCounter, numWordsOnPageCounter, links, wordsOccurringInPage);
                    wordOnPage->~StringIntMap();
                    wordOnPage = new StringIntMap();
                    wordsOccurringInPage.clear();
                    links.clear();
                    numLinksOnPageCounter = 0;
                    numWordsOnPageCounter = 0;
                    uniqueWordsOnPageCounter = 0;
                    /* Reset all the counters */
                }
                firstIteration = false;
                /* Read in because you want the PAGE then the url next to it */
                webFile >> url;
            }
                /* Reads a hyperLink, calculates the index at which the hyperLink would exist inside the StringToIntMap
                * hash table. It then determines if the hyperLink in question exists inside the hash table. If it exists
                * inside the hash table, a reference value is given that corresponds to the index at which this link
                * would exist inside the Vector of WebPages. Reference value is given on first file read */
            else if (readInData == "LINK") {
                /* Read in because you want LINK then the url next to it */
                webFile >> readInData;
                /* If the link is not a dead end */
                if (webPageIntMap.find(readInData)) {
                    int location = webPageIntMap[readInData];
                    links.push_back(location);
                    numLinksOnPageCounter++;
                }
            } /* All other words are processed */
            else {
                /* These are the words that OCCUR within a particular page */
                wordsOccurringInPage.push_back(readInData);
                numWordsOnPageCounter++;
                /* This is adding only non-duplicate words from a particular page*/
                if (!wordOnPage->find(readInData)) {
                    /* A lot is happening here. We are taking the index at which the page exists
                    * in the page structure. Then getting the index at which the word exists in the word structure.
                    * then we are accessing the index at which the word exists, adding the index at which the link exists
                    * to the word struct. Then while inside the word struct we are incrementing num pages to signify
                    * how many pages the word is on*/
                    wordOnPage->insert(readInData, uniqueWordsOnPageCounter);
                    int linkIndex = webPageIntMap[url];
                    int wordIndex = wordIntMap[readInData];
                    everyDistinctWordVec.at(wordIndex).pages.push_back(linkIndex);
                    everyDistinctWordVec.at(wordIndex).numPages++;
                    uniqueWordsOnPageCounter++;
                }
            }
        }
    }

    /* GOOGLE PAGE RANK */
    std::cout << "Google page rank" << endl;

    for (int x = 0; x < 50; x++) {
        for (auto &page: pages) {
            page.newWeight = .1;
        }
        for (size_t i = 0; i < pages.size(); i++) {
            /* Every page that pages.at(j) links too*/
            if (pages.at(i).links.empty()) {
                pages.at(i).newWeight += .9 * pages.at(i).weight;
            } else {
                for (size_t j = 0; j < pages.at(i).links.size(); j++) {
                    /*Increase new_weight[j] by 0.9 * pages[i].weight / pages[i].num_links
                    (this spreads 90% of the weight of a page uniformly across its
                    outgoing links. As a special case, if page I have no outgoing links,
                    please keep that 90% on the page by increasing new_weight[i] by
                    pages[i].weight * 0.9 */

                    int index = pages.at(i).links.at(j) - 1;
                    try {
                        pages.at(index).newWeight += (.9 * pages.at(i).weight) / (double) pages.at(
                                i).numLinks;     // vector::at throws an out-of-range
                    }
                    catch (const std::out_of_range &oor) {
                        std::cerr << "Out of Range error: " << oor.what() << '\n';
                        std::cout << "INDEX VALUE = " << index << endl;
                        std::cout << " I = " << i << endl;
                        std::cout << "J = " << j << endl;
                    }
                }
            }
        }

        for (size_t i = 0; i < pages.size(); i++) {
            pages.at(i).weight = pages.at(i).newWeight;
            /*For each page i, set pages[i].weight = new_weight[i].
            (note that these are three separate "for each page i" loops, one after
            the other. also note that weights on pages are never created or destroyed
            in each iteration of Pagerank --- they are only redistributed, so the
            total of all the weights should always be 1).*/
        }
    }

    cout << "Finished" << endl;
    delete wordOnPage;

    int myLookUp = wordIntMap["pancakes"];
    for (int i = 0; i < everyDistinctWordVec.at(myLookUp).pages.size(); i++) {
        int tmp = everyDistinctWordVec.at(myLookUp).pages.at(i);
        cout << pages.at(tmp).weight << endl;
    }

    /* Enter loop to ask for query */
    processKeystrokes();

    return 0;
}

/** Note I could insert these string values of page into the hash table
 * then when I am checking all my hyper links I can call find. If I find it
 * I can check its location, and store the corresponding location inside of
 * my vector<int> */

