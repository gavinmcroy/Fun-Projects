#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits);

int main() {
    std::vector<int> number = {9,8,7,6,5,4,3,2,1,0};
    std::vector<int> answer = plusOne(number);

    return 0;
}

vector<int> plusOne(vector<int> &digits) {
    /* Convert digits into one consecutive string, then string to number, preform operation
     * convert entire number back to string, then copy each individual digits into vector
     * after converting from char to int */
    std::vector<int> answer;
    const int OFFSET = 48;
    string stringNumber;
    for (int i = 0; i < digits.size(); i++) {
        stringNumber += char(OFFSET + digits[i]);
    }

    /* Conviently this is invalid since the solution uses absurdly large numbers */
    long long value = stoll(stringNumber);
    value += 1;
    stringNumber = std::to_string(value);

    for (int i = 0; i < stringNumber.size(); i++) {
        int toInt = stringNumber[i] - OFFSET;
        answer.push_back(toInt);
    }

    return answer;
}