#include <iostream>
#include <string>

using namespace std;

bool repeatedSubstringPattern(string s);

int main() {
    string value = "abab";
    std::cout << repeatedSubstringPattern("abaabaa");
    //std::cout << value.substr(0,2);
    return 0;
}

bool repeatedSubstringPattern(string s) {
    if (s.size() < 2) {
        return false;
    }

    /* Test if all letters are the same */
    char temp = s[0];
    bool allSame = true;
    for (char x: s) {
        if (x != temp) {
            allSame = false;
        }
    }
    if (allSame) {
        return true;
    }

    /* Our substring must be at least 2 letters, so start with the first two letters */
    string possibleSol;
    int startingSize = 2;
    for (int i = 2; i < s.size(); i++) {
        int increment = 0;
        /* if at least half the string has yet to yield a solution then there is no substring */
        if (startingSize > (s.size() / 2) + 1) {
            break;
        }
        string sub = s.substr(0, startingSize);

        /* Compare our substring at 0, for each letter, if one letter differs, unsuccessful match, exit sub loop */
        for (int j = i; j < s.size(); j++) {
            /* invalid solution */
            if (sub[increment] != s[j]) {
                break;
            }
            increment++;

            /* Solution found */
            if (increment >= sub.size()) {
                possibleSol = sub;
                break;
            }
        }
        startingSize++;
    }

    if (possibleSol.empty()) {
        return false;
    }


    /* breaks on abaabaa*/

    /* Take our possible substr and see if it can be appended to create the start string letter by letter */
    string check;
    int incr = 0;
    for(int i = 0; i < s.size(); i++ ){
        if(incr >= possibleSol.size()){
            incr = 0;
        }
        check += possibleSol[incr];
        incr++;
    }

    if (s != check) {
        return false;
    }

    return true;
}