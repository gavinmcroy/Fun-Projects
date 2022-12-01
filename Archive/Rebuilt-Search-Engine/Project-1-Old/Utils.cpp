#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>

#include "StoredWebPages.h"
#include "StringIntMap.h"
#include "StoredWords.h"

using namespace std;

/** WHERE I LEFT OFF
 *
 *              */


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

/* TODO IMPLEMENT */
void predict(string query) {
    cout << color_green << "Here is where query results for '"
         << color_white << query
         << color_green << "' should go\n";
}

void processKeystrokes() {
    int ch = 0;
    string query;

    while (ch != '\n') {
        cout << clear_screen << color_green << "Search keyword: "
             << color_white << query
             << color_green << "-\n\n";

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

/* This shows how to use some starter code above */
int main() {
    StoredWebPages webPages;
    StoredWords storedWords;

    StringIntMap webPageIntMap;
    StringIntMap wordIntMap;
    StringIntMap * wordOnPage = new StringIntMap;

    cout << color_green << "Reading input..." << endl;
    const char *filename = "/Users/gavintaylormcroy/Desktop/webpages.txt";
    istringstream webfile(readWebpagesFast(filename));

    std::vector<StoredWebPages::Webpage> pages = webPages.getWebPages();
    std::vector<StoredWords::Word> everyDistinctWordVec = storedWords.getWords();

    /* I could insert these string values of page into the hash table
     * then when I am checking all my hyperlinks I can call find. If I find it
     * I can check its location, and store the corresponding location inside
     * my vector<int> */

    int totalWebPages = 0;
    int totalDistinctWords = 0;
    string data;

    /* Insert all PAGES and DISTINCT words into separate hash table */
    while (webfile >> data) {
        if (data == "PAGE") {
            webfile >> data;
            webPageIntMap.insert(data, totalWebPages);
            totalWebPages++;
        } else if (data == "LINK ") {
            string hyperLinkTMP;
            /* This is catching the hyperlink and just trashing it */
            webfile >> hyperLinkTMP;
        } else {
            /* Store all the DISTINCT words in a map/hash table THAT containing
             * the words INDEX/POS for the words INSIDE the vector located in StoredWords */
            if (!wordIntMap.find(data)) {
                wordIntMap.insert(data, totalDistinctWords);
                /* This is adding the words to the vector */
                everyDistinctWordVec.emplace_back(data);
                totalDistinctWords++;
            }
        }
    }
//    cout << words.size() << endl;
//    cout << totalDistinctWords << endl;
    cout << "Indexing..." << endl;


    /* Reset the file being read */
    webfile.clear();
    webfile.seekg(0);

    /* 26,881 Pages, 184,408 Hyperlinks, 18,896,392 words */

    /* COUNTERS */
    string readInValue;
    string url;
    int numLinks = 0;
    int numWords = 0;
    vector<int> links;
    vector<string> wordsOccurringInPage;
    /* COUNTERS */

    /* Parameters */
    bool first = true;
    string hyperLink;
    int tmpUniqueWords = 0;
    /* Parameters */

    /* This builds our webpage vector with all appropriate info */
    while (webfile >> readInValue) {
        if (readInValue == "PAGE") {
            if (!first) {
                /* Reset all the counters by adding the WebPage + all its data */
                pages.emplace_back(url, numLinks, numWords, links, wordsOccurringInPage);
                wordOnPage->~StringIntMap();
                wordOnPage = new StringIntMap();
                wordsOccurringInPage.clear();
                numLinks = 0;
                numWords = 0;
                tmpUniqueWords = 0;
                /* Reset all the counters */
            }
            first = false;
            /* Read in because you want the PAGE then the url next to it */
            webfile >> url;
        } /* Reads a hyperLink, calculates the index at which the hyperLink would exist inside inside the StringToIntMap
           * hash table. It then determines if the hyperLink in question exists inside the hash table. If it exists
           * inside the hash table, a reference value is given that corresponds to the index at which this link
           * would exist inside the Vector of WebPages. Reference value is given on first file read */
        else if (readInValue == "LINK") {
            /* Read in because you want LINK then the url next to it */
            webfile >> hyperLink;
            /* If the link is not a dead end */
            if (webPageIntMap.find(hyperLink)) {
                int hash = webPageIntMap[hyperLink];
                links.push_back(hash);
                numLinks++;
            }
        } /* Regular Words are read in and added to the wordsOccurring vector*/
        else {
            /* These are the words that OCCUR within the scope of a page */

            wordsOccurringInPage.push_back(readInValue);
            numWords++;

            /* A lot is happening here. We are taking the index at which the page exists
             * in the page structure. Then getting the index at which the word exists in the word structure.
             * then we are accessing the index at which the word exists, adding the index at which the link exists
             * to the word struct. Then while inside the word struct we are incrementing num pages to signify
             * how many pages the word is on*/

            /* This is adding only non-duplicate words from a particular page*/
            if (!wordOnPage->find(readInValue)) {
                wordOnPage->insert(readInValue, tmpUniqueWords);
                int linkIndex = webPageIntMap[url];
                int wordIndex = wordIntMap[readInValue];
                everyDistinctWordVec.at(wordIndex).pages.push_back(linkIndex);
                everyDistinctWordVec.at(wordIndex).numPages++;
                tmpUniqueWords++;
                /* This is adding the words to the vector */
                //words.emplace_back(data);
                //totalDistinctWords++;
            }


            /* TODO THIS IS counting duplicates */
//            int linkIndex = webPageIntMap[url];
//            int wordIndex = wordIntMap[readInValue];
//            words.at(wordIndex).pages.push_back(linkIndex);
//            words.at(wordIndex).numPages++;
        }
    }
    delete wordOnPage;

    int myLookUp = wordIntMap["dabo"];
    cout << everyDistinctWordVec.at(myLookUp).text << endl;
    // cout << "Frequency " << myLookUp << endl;
    cout << "Total Pages " << everyDistinctWordVec.at(myLookUp).numPages << endl;
    myLookUp = wordIntMap["football"];
    cout << everyDistinctWordVec.at(myLookUp).text << endl;
    //cout << "Frequency " << myLookUp << endl;
    cout << "Total Pages " << everyDistinctWordVec.at(myLookUp).numPages << endl;
    myLookUp = wordIntMap["pancakes"];
    cout << everyDistinctWordVec.at(myLookUp).text << endl;
    //cout << "Frequency " << words.at(myLookUp). << endl;
    cout << "Total Pages " << everyDistinctWordVec.at(myLookUp).numPages << endl;

    for (int i = 0; i < everyDistinctWordVec.at(myLookUp).pages.size(); i++) {
        cout << everyDistinctWordVec.at(myLookUp).pages.at(i) << endl;
    }

    /* DEBUG */
//    cout << pages.at(0).url << endl;
//    cout << pages.at(0).numLinks << endl;
//
//    cout << pages.at(0).words.size() << endl;
//    cout << pages.at(0).words.at(0) << endl;
    /* DEBUG */

    // Enter loop to ask for query
    processKeystrokes();

    return 0;
}
