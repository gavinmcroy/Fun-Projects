#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle);

int main() {
    std::string haystack = "bigoldmanwalkingdowntheroad";
    std::string needle = "road";
    std::cout << strStr(haystack, needle);
    return 0;
}

int strStr(string haystack, string needle) {
    for (int i = 0; i < haystack.size(); i++) {
        /* first letter of search word lines up with list of words */
        if (haystack[i] == needle[0]) {
            bool falsePositive = false;

            for (int j = 0; j < needle.size(); j++) {
                /* Boundary check to ensure haystack can keep incrementing within bounds */
                if (i + j > haystack.size()) {
                    return false;
                }

                /* There is a difference in letters, false positive*/
                if (haystack[i + j] != needle[j]) {
                    falsePositive = true;
                    break;
                }
            }
            /* if no false positive, return the index the first letter was spotted */
            if (!falsePositive) {
                return i;
            }
        }
    }
    return -1;
}
