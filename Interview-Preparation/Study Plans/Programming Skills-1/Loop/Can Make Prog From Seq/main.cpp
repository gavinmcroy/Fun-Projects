#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canMakeArithmeticProgression(vector<int> &arr);

int main() {
    vector<int> nums = {13, 12, -12, 9, 9, 16, 7, -10, -20, 0, 18, -1, -20, -10, -8, 15, 15, 16, 2, 15};
    std::cout << canMakeArithmeticProgression(nums);
    return 0;
}

bool canMakeArithmeticProgression(vector<int> &arr) {
    std::sort(arr.begin(), arr.end(), std::greater<>());
    if (arr.size() == 2) {
        return true;
    }
    int arithmeticDif = arr[0] - arr[1];
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] - arr[i + 1] != arithmeticDif) {
            return false;
        }
    }
    return true;
}