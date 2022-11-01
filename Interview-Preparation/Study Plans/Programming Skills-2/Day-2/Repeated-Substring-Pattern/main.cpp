#include <iostream>
#include <string>

using namespace std;

bool repeatedSubstringPattern(string s);

int main() {
    string value = "abab";
    std::cout << repeatedSubstringPattern("aabaab");
    //std::cout << value.substr(0,2);
    return 0;
}

bool repeatedSubstringPattern(string s) {
    if (s.size() < 2) {
        return false;
    }

    /* the first letter of the string must repeat, so once it repeats, take the substring */
    char reference = s[0];
    string temp;
    for (int i = 1; i < s.size(); i++) {
        /* this could be a potential substr */
        if (reference == s[i]) {
            temp = s.substr(0, i);
            break;
        }
    }
    std::cout << temp;

    return false;

}