#include <iostream>
#include <string>

using namespace std;


bool areAlmostEqual(string s1, string s2);

int main() {
    std::cout << areAlmostEqual("bank", "bnak");
    return 0;
}

bool areAlmostEqual(string s1, string s2) {
    if (s1 == s2) {
        return true;
    }

    for (int i = 0; i < s2.size(); i++) {
        for (int j = i + 1; j < s2.size(); j++) {
            std::swap(s2[i], s2[j]);
            /* check for solution */
            if (s1 == s2) {
                return true;
            }
            std::swap(s2[i], s2[j]);
        }
    }
    return false;
}
