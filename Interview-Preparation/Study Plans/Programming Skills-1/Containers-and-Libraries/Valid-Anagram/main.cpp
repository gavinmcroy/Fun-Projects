#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isAnagram(string s, string t);


int main() {
    std::string s = "anagram";
    std::string t = "nagaram";
    std::cout << isAnagram(s, t);
    return 0;
}

bool isAnagram(string s, string t) {
    /* cannot be anagram if the size is different */
    if (s.size() != t.size()) {
        return false;
    }

    /* anagram contains all the same letters, so if we cycle through all the letters
     * and add them to a map, we can go through the word and ensure there are 2 of each letter */
    std::map<char, int> map1;
    std::map<char, int> map2;
    for (int i = 0; i < s.size(); i++) {
        map1[s[i]]++;
        map2[t[i]]++;
    }

    for (int i = 0; i < s.size(); i++) {
        if (map1[s[i]] != map2[s[i]]) {
            return false;
        }
    }

    return true;
}