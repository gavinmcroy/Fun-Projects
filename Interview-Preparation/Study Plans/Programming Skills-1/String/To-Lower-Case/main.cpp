#include <iostream>
#include <string>

using namespace std;

string toLowerCase(string s);

int main() {
    std::cout << toLowerCase("abc");
    return 0;
}

string toLowerCase(string s) {
    const int OFFSET = 32;
    std::string lowerCase;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            lowerCase += (char) (s[i] + OFFSET);
        } else {
            lowerCase += s[i];
        }
    }
    return lowerCase;
}
