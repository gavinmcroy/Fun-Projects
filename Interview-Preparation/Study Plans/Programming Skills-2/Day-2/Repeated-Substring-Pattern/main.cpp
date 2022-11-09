#include <iostream>
#include <string>

using namespace std;

bool repeatedSubstringPattern(string s);

string largestSubString(string s);

bool smallestSubString(string s);

int main() {
    string value = "abaabaa";
    string value2 = "abababab";
    string value3 = "ababababab";
    string value4 = "aabaab";
    //std::cout << largestSubString(value3);
    std::cout << repeatedSubstringPattern(value);
    std::cout << smallestSubString(value);
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
                /* See if we can construct a string with the given possible substring */
                possibleSol = sub;
                string test;
                int amount = s.size() / possibleSol.size();
                for (int i = 0; i < amount; i++) {
                    test += possibleSol;
                }
                if (test == s) {
                    return true;
                }
                break;
            }
        }
        startingSize++;
    }

    if (possibleSol.empty()) {
        return false;
    }

    return false;
}

string largestSubString(string s) {
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
    std::cout << possibleSol << std::endl;
    return possibleSol;
}

bool smallestSubString(string s) {
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
                string test;
                int amount = s.size() / possibleSol.size();
                for (int i = 0; i < amount; i++) {
                    test += possibleSol;
                }
                if (test == s) {
                    return true;
                }
                break;
            }
        }
        startingSize++;
    }
    return false;
}