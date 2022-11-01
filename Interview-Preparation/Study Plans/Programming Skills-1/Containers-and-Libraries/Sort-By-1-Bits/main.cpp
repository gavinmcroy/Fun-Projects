#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortByBits(vector<int> &arr);

int countSetBits(int n);


int main() {
    std::vector<int> nums = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    std::vector<int> sortedByBits = sortByBits(nums);
    for (int i: sortedByBits) {
        std::cout << i << " " << std::endl;
    }

    return 0;
}

vector<int> sortByBits(vector<int> &arr) {
    vector<int> temp;
    temp = arr;

    sort(temp.begin(), temp.end(), [](const auto &lhs, const auto &rhs) {
        int val1 = countSetBits(lhs);
        int val2 = countSetBits(rhs);
        if (val1 == val2) {
            return lhs < rhs;
        } else {
            return countSetBits(lhs) < countSetBits(rhs);
        }
    });

    return temp;
}

int countSetBits(int n) {
    int hammingWeight = 0;
    for (int i = 0; i < 32; i++) {
        if (n & (1 << i)) {
            hammingWeight++;
        }
    }
    return hammingWeight;
}
