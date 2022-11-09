#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int evalRPN(vector<string> &tokens);

int main() {
    vector<string> data = {"11", "+", "-"};
    return 0;
}

int evalRPN(vector<string> &tokens) {
    /* General algorithm
     * Push numbers until we run into an operator
     * if operator pop 2 numbers off, apply operation, push them back to stack
     * Repeat until stack is empty */
    
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "+") {

        } else if (tokens[i] == "-") {

        } else if (tokens[i] == "*") {

        } else if (tokens[i] == "/") {

        } else {

        }
    }
}
