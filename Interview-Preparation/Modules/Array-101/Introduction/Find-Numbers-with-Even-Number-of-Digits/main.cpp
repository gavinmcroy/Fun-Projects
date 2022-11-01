#include <iostream>
#include <vector>
#include <string>

int findNumbers(std::vector<int> &nums);

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int findNumbers(std::vector<int> &nums) {
    int totalEvenDigit = 0;
    for (int val : nums) {
        std::string myString = std::to_string(val);
        if (myString.size() % 2 == 0) {
            totalEvenDigit++;
        }
    }
    return totalEvenDigit;
}
