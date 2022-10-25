#include <iostream>
#include <string>

using namespace std;

string interpret(string command);

int main() {
    std::cout << interpret("G()()()()(al)");
    return 0;
}

string interpret(string command) {
    /* 3 Conditions "G" "()" "(AL)" */
    std::string answer;
    for (int i = 0; i < command.size(); i++) {
        if (command[i] == 'G') {
            answer += "G";
        }
            /* since () is two characters we need to move i forward again to prevent duplicate processing */
        else if (command[i] == '(' && command[i + 1] == ')') {
            answer += "o";
            i++;
        } else {
            answer += "al";
            i += 3;
        }
    }
    return answer;
}

