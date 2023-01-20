#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <termios.h>
#include <unistd.h>
#include "StoredWebPages.h"
#include "StringIntMap.h"
#include "StoredWords.h"

using namespace std;

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

StoredWebPages webPages(25000);
StoredWords storedWords(180000);
StringIntMap webPageIntMap;
StringIntMap wordIntMap;
auto *wordOnPage = new StringIntMap;
std::vector<StoredWebPages::Webpage> pages = webPages.getWebPages();
std::vector<StoredWords::Word> everyDistinctWordVec = storedWords.getWords();

void predict(const string &query);

string readWebpagesFast(const char *filename);

void processKeystrokes();

int main() {
    const char *fileNameMac = "/Users/gavintaylormcroy/Documents/webpages.txt";
    const char *filenameLinux = "/home/gav/Documents/webpages.txt";
    string readInData;

    cout << color_green << "Reading input..." << endl;
    istringstream webFile(readWebpagesFast(fileNameMac));

    /* Insert all PAGES and DISTINCT words into separate hash table */
    int totalWebPages = 0;
    int totalDistinctWords = 0;
    while (webFile >> readInData) {
        if (readInData == "PAGE") {
            webFile >> readInData;
            webPageIntMap.insert(readInData, totalWebPages);
            totalWebPages++;
        } else if (readInData == "LINK ") {
            /* This is catching the hyperlink and just trashing it since we are counting total pages */
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

    /* This is where we begin the building of our data structures */
    cout << "Indexing..." << endl;
    /* Reset the file being read */
    webFile.clear();
    webFile.seekg(0);


    /* 26,881 Pages, 184,408 Hyperlinks, 18,896,392 words */
    /* This builds our webpage vector with all appropriate info */
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
                    pages.at(index).newWeight += (.9 * pages.at(i).weight) / (double) pages.at(
                            i).numLinks;     // vector::at throws an out-of-range
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

    int myLookUp = wordIntMap["pancake"];
    for (int i = 0; i < everyDistinctWordVec.at(myLookUp).pages.size(); i++) {
        int tmp = everyDistinctWordVec.at(myLookUp).pages.at(i);
        cout << pages.at(tmp).weight << endl;
    }

    processKeystrokes();
    return 0;
}

/* TODO IMPLEMENT */
void predict(const string &query) {
    cout << color_green << "Next word: '"
         << color_white << "query"
         << color_green << "'\n";
    /* TEST CODE */
}

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

void processKeystrokes() {
    int ch = 0;
    string query;
    while (ch != '\n') {
        cout << clear_screen << color_green << "Search keyword: "
             << color_white << query
             << color_green << "-\n\n";

        int wordIndex = wordIntMap[query];
        cout << color_yellow << "'" << everyDistinctWordVec.at(wordIndex).numPages << color_green << "' pages match"
             << endl;

        cout << color_yellow << "'" << "Place holder text" << color_green << "' pages match"
             << endl;
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
