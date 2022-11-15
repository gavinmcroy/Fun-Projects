#include <iostream>
#include <string>
#include <vector>

using namespace std;


string add(string num1, string num2);

vector<int> addToArrayForm(vector<int> &num, int k) {
    string num2 = to_string(k);
    string num1;
    string solution;
    vector<int> intSolution;
    int hangingDigit = 0;
    const int OFFSET = 48;

    /* Convert our numArray into a string */
    for (int i = 0; i < num.size(); i++) {
        num1 += num[i] + OFFSET;
    }

    /* Step 1 would be to insert 0's in front of num1 until its equal to num2 */
    if (num1.size() < num2.size()) {
        while (num1.size() < num2.size()) {
            num1.insert(num1.begin(), '0');
        }
    } else if (num2.size() < num1.size()) {
        while(num2.size() < num1.size()){
            num2.insert(num2.begin(), '0');
        }
    }

    int j = num2.size() - 1;
    for (int i = num1.size() - 1; i >= 0; i--) {
        int tempDigit = 0;
        /* Char to Int Conversion */
        int digit1 = (int) (num1[i] - OFFSET);
        int digit2 = (int) (num2[j] - OFFSET);
        tempDigit = digit1 + digit2;
        /* The two digits added together now are greater than 9 and have a hanging digit */
        if (tempDigit > 9) {
            tempDigit -= 10;
            if (hangingDigit >= 1) {
                tempDigit += hangingDigit;
            }
            hangingDigit = 1;
        } else {
            if (hangingDigit >= 1) {
                tempDigit += hangingDigit;
            }
            /* Means it was 9+1 */
            if (tempDigit >= 10) {
                tempDigit -= 10;
                hangingDigit = 1;
            } else {
                hangingDigit = 0;
            }
        }
        // std::cout << "DIGIT1: " << digit1 << " DIGIT2: " << digit2 << std::endl;
        /* Convert Int to Char and add to the solution string */

        /* We are on the loops last iteration, so we need to add the hanging digit */
        if (i == 0) {
            solution.push_back(tempDigit + OFFSET);
            if (hangingDigit == 1) {
                solution.push_back(1 + OFFSET);
            }
        } else {
            solution.push_back(tempDigit + OFFSET);
        }
        j--;
    }
    /* Adding last digits first reverses the answer , so reverse it back */
    for (int i = 0; i < solution.size(); i++) {
        intSolution.push_back(solution[i] - OFFSET);
    }
    std::reverse(intSolution.begin(), intSolution.end());
    return intSolution;
}

int main() {
    std::vector<int> vec1 = {1,2,0,0};
    int k = 34;
    std::vector<int> solution = addToArrayForm(vec1, k);
    for (int x: solution) {
        std::cout << x;
    }
    std::cout << std::endl;
    std::cout << add("34", "1200");
    return 0;
}

string add(string num1, string num2) {
    /* Step 1 would be to insert 0's in front of num1 until its equal to num2 */
    if(num1.size() < num2.size()){
        while (num1.size() < num2.size()) {
            num1.insert(num1.begin(), '0');
        }
    }else if(num2.size() < num1.size()){
        while(num2.size() < num1.size()){
            num2.insert(num2.begin(), '0');
        }
    }

    string solution;
    int hangingDigit = 0;
    const int OFFSET = 48;
    int j = num2.size() - 1;
    for (int i = num1.size() - 1; i >= 0; i--) {
        int tempDigit = 0;
        /* Char to Int Conversion */
        int digit1 = (int) (num1[i] - OFFSET);
        int digit2 = (int) (num2[j] - OFFSET);
        tempDigit = digit1 + digit2;
        /* The two digits added together now are greater than 9 and have a hanging digit */
        if (tempDigit > 9) {
            tempDigit -= 10;
            if (hangingDigit >= 1) {
                tempDigit += hangingDigit;
            }
            hangingDigit = 1;
        } else {
            if (hangingDigit >= 1) {
                tempDigit += hangingDigit;
            }
            /* Means it was 9+1 */
            if (tempDigit >= 10) {
                tempDigit -= 10;
                hangingDigit = 1;
            } else {
                hangingDigit = 0;
            }
        }
        // std::cout << "DIGIT1: " << digit1 << " DIGIT2: " << digit2 << std::endl;
        /* Convert Int to Char and add to the solution string */

        /* We are on the loops last iteration, so we need to add the hanging digit */
        if (i == 0) {
            solution.push_back(tempDigit + OFFSET);
            if (hangingDigit == 1) {
                solution.push_back(1 + OFFSET);
            }
        } else {
            solution.push_back(tempDigit + OFFSET);
        }
        j--;
    }
    /* Adding last digits first reverses the answer , so reverse it back */
    std::reverse(solution.begin(), solution.end());
    return solution;
}
