#include <iostream>
#include <string>

using namespace std;

string mergeAlternately(string word1, string word2);

int main() {
    std::cout << mergeAlternately("ABC", "ABCDE");
    return 0;
}

string mergeAlternately(string word1, string word2) {
    string tmp;
    bool alternate = true;
    int firstWord = 0;
    int secondWord = 0;
    while (true) {
        /* Since we start with alternate at true, this will hit first */
        if (alternate && (firstWord < word1.length())) {
            tmp += (word1[firstWord]);
            firstWord++;
        } else if (!alternate && (secondWord < word2.length())) {
            tmp += (word2[secondWord]);
            secondWord++;
        }
        /* Both words have been cycled */
        if (secondWord > word2.length() - 1 && firstWord > word1.length() - 1) {
            break;
        }
        
        alternate = !alternate;
    }
    return tmp;
}