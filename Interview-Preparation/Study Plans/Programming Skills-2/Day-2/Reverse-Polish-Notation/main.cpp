#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int evalRPN(vector<string> &tokens);

std::pair<int, int> extractor(stack<int> &st);

int main() {
    vector<string> data = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    std::cout << evalRPN(data);
    return 0;
}

int evalRPN(vector<string> &tokens) {
    stack<int> answer;
    /* General algorithm
     * Push numbers until we run into an operator
     * if operator pop 2 numbers off, apply operation, push them back to stack
     * Repeat until stack is empty */

    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "+") {
            /* if stack is (9 3 +) (we would do 9+3) so val2 (operator) val1*/
            pair<int, int> values = extractor(answer);
            int operation = values.second + values.first;
            answer.push(operation);
        } else if (tokens[i] == "-") {
            pair<int, int> values = extractor(answer);
            int operation = values.second - values.first;
            answer.push(operation);
        } else if (tokens[i] == "*") {
            pair<int, int> values = extractor(answer);
            int operation = values.second * values.first;
            answer.push(operation);
        } else if (tokens[i] == "/") {
            pair<int, int> values = extractor(answer);
            int operation = values.second / values.first;
            answer.push(operation);
        } /* No operator means we push onto the stack */
        else {
            answer.push(stoi(tokens[i]));
        }
    }
    /* the last value on the stack should be the answer */
    return answer.top();
}

std::pair<int, int> extractor(stack<int> &st) {
    int val1 = st.top();
    st.pop();
    int val2 = st.top();
    st.pop();
    return pair<int, int>(val1, val2);
}