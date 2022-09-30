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
void predict(const string &query) {
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

int main() {

    StoredWebPages webPages;
    StoredWords storedWords;
    StringIntMap webPageIntMap;
    StringIntMap wordIntMap;
    auto *wordOnPage = new StringIntMap;
    std::vector<StoredWebPages::Webpage> pages = webPages.getWebPages();
    std::vector<StoredWords::Word> everyDistinctWordVec = storedWords.getWords();
    const char *filename = "/Users/gavintaylormcroy/Desktop/webpages.txt";
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
                    numLinksOnPageCounter = 0;
                    numWordsOnPageCounter = 0;
                    uniqueWordsOnPageCounter = 0;
                    /* Reset all the counters */
                }
                firstIteration = false;
                /* Read in because you want the PAGE then the url next to it */
                webFile >> url;
            }
                /* Reads a hyperLink, calculates the index at which the hyperLink would exist inside inside the StringToIntMap
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

    /* TEST SEARCH */
    int myLookUp = wordIntMap["dabo"];
    cout << everyDistinctWordVec.at(myLookUp).text << endl;
    cout << "Total Pages " << everyDistinctWordVec.at(myLookUp).numPages << endl;

    myLookUp = wordIntMap["football"];
    cout << everyDistinctWordVec.at(myLookUp).text << endl;
    cout << "Total Pages " << everyDistinctWordVec.at(myLookUp).numPages << endl;

    myLookUp = wordIntMap["pancakes"];
    cout << everyDistinctWordVec.at(myLookUp).text << endl;
    cout << "Total Pages " << everyDistinctWordVec.at(myLookUp).numPages << endl;

    myLookUp = wordIntMap["pancake"];
    cout << everyDistinctWordVec.at(myLookUp).text << endl;
    cout << "Total Pages " << everyDistinctWordVec.at(myLookUp).numPages << endl;
    /* TEST SEARCH */

    delete wordOnPage;

    /* Enter loop to ask for query */
    processKeystrokes();

    return 0;
}

/** Note I could insert these string values of page into the hash table
 * then when I am checking all my hyper links I can call find. If I find it
 * I can check its location, and store the corresponding location inside of
 * my vector<int> */