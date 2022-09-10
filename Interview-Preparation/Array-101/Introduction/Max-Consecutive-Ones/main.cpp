#include <iostream>
#include <vector>

int findMaxConsecutiveOnes(std::vector<int> &nums);

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int findMaxConsecutiveOnes(std::vector<int> &nums) {
    int counter = 0;
    int max = 0;
    for (int val : nums) {
        std::cout << val << std::endl;
        if (val == 1) {
            counter++;
        } else {
            counter = 0;
        }
        if (counter > max) {
            max = counter;
        }
    }
    return max;
}