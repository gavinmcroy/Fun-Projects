#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits);

int main() {
    std::vector<int> number = {5,7,4,9,9,9};
    std::vector<int> answer = plusOne(number);

    return 0;
}

vector<int> plusOne(vector<int> &digits) {
    std::vector<int> answer = digits;
    /* If the last digit is a 9 */
    if (answer[answer.size() - 1] == 9) {
        /* check all consecutive digits for total amount of 9's. At the index it stops at
         * i - 1 should be where you increment by 1. If they are all 9, just rebuild answer with size+1 and make
         * left most digit 1 */
        int i;
        bool allNine = true;
        for (i = answer.size() - 1; i >= 0; i--) {
            if (answer[i] != 9) {
                allNine = false;
                break;
            }
        }
        /* The digits aren't just a list of 9's */
        if (!allNine) {
            answer[i]++;
            for (int j = i+1; j < answer.size(); j++) {
                answer[j] = 0;
            }
        } else {
            answer.clear();
            for (int j = 0; j < digits.size() + 1; j++) {
                answer.push_back(0);
            }
            answer[0] = 1;
        }


    } else {
        answer[answer.size() - 1]++;
        return answer;
    }
    return answer;
}

//vector<int> plusOne(vector<int> &digits) {
//    /* Convert digits into one consecutive string, then string to number, preform operation
//     * convert entire number back to string, then copy each individual digits into vector
//     * after converting from char to int */
//    std::vector<int> answer;
//    const int OFFSET = 48;
//    string stringNumber;
//    for (int i = 0; i < digits.size(); i++) {
//        stringNumber += char(OFFSET + digits[i]);
//    }
//
//    /* Conveniently this is invalid since the solution uses absurdly large numbers */
//    unsigned long long value = stoll(stringNumber);
//    value += 1;
//    stringNumber = std::to_string(value);
//
//    for (int i = 0; i < stringNumber.size(); i++) {
//        int toInt = stringNumber[i] - OFFSET;
//        answer.push_back(toInt);
//    }
//
//    return answer;
//}