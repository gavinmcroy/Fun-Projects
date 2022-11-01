#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool isAlienSorted(vector<string> &words, string order);

int main() {

    string alphabet = "hlabcdefgijkmnopqrstuvwxyz";
    vector<string> words = {"apap", "app"};
    std::cout << isAlienSorted(words, alphabet) << std::endl;
    return 0;
}

bool isAlienSorted(vector<string> &words, string order) {
    /* We take our alphabet and assign numbers to each letter based on there order (if z is 1 than alphabet[z] = 1 */
    map<char, int> alphabet;
    for (int i = 0; i < order.size(); i++) {
        alphabet.insert(pair<char, int>(order[i], i));
    }
    /* Lexicographical rules
     * If a word is longer word vs words than word comes first
     * words should be in alphabetical order according to the given alphabet */
    for (int i = 0; i < words.size(); i++) {
        /* This means we are on the last word, so it must be sorted */
        if (i + 1 >= words.size()) {
            break;
        }
        /* we first check if the first letter is greater. This automatically fails the loop since it's not in order */
        if (alphabet[words[i][0]] > alphabet[words[i + 1][0]]) {
            return false;
        } /* This means the first letter is the same, time to check each letter */
        else if (alphabet[words[i][0]] == alphabet[words[i + 1][0]]) {
            for (int j = 0; j < words[i].size(); j++) {
                /* The first word is longer, and has exceeded the length of the second word without
                 * detecting a letter difference. Special case for the letter of the first word
                 * actually being smaller than the last letter of the second word */
                if (j > words[i + 1].size() - 1) {
                    return false;
                }
                /* This will spot if there is a letter greater */
                if (alphabet[words[i][j]] > alphabet[words[i + 1][j]]) {
                    return false;
                } /* if a single letter is less, than the first word
                   * is in the correct order (apa < app) */
                else if (alphabet[words[i][j]] < alphabet[words[i + 1][j]]) {
                    break;
                }
            }
        }

    }
    return true;

}