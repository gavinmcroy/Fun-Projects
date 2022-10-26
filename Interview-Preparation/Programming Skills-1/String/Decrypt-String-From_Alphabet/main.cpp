#include <iostream>
#include <string>
#include <vector>

using namespace std;

string freqAlphabets(string s);

int main() {
    std::string string1 = "10#11#12";
    std::cout << freqAlphabets(string1);
    return 0;
}

string freqAlphabets(string s) {
    /* Parse the string first into numerical equivalents */
    std::vector<int> nums;
    std::string finalAnswer;
    /* for every hashtag you hit you go two back */
    for (int i = 0; i < s.length(); i++) {
        std::string stringToConvert;
        bool foundHashTag = false;
        /* Make sure we are within bounds when checking for hashtag */
        if (i + 2 < s.length()) {
            /* check 3 ahead, if hashtag, convert number and move i ahead.
             * if none add single digit */
            for (int j = 0; j < 3; j++) {
                /* The previous two numbers are needed*/
                if (s[i + j] == '#') {
                    stringToConvert += s[i + j - 2];
                    stringToConvert += s[i + j - 1];
                    i += 2;
                    foundHashTag = true;
                }
            }
        }
        if (!foundHashTag) {
            stringToConvert += s[i];
        }
        int value = stoi(stringToConvert);
        /* Value - 1 is required because final answer will be 1 letter higher than it should be */
        finalAnswer += (char) (value - 1 + 'a');
    }
    return finalAnswer;
}
