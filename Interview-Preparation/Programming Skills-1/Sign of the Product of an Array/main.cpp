#include <iostream>
#include <vector>

using namespace std;

int signFunc(int x) {
    if (x < 0) {
        return -1;
    } else if (x > 0) {
        return 1;
    } else {
        return 0;
    }
}

int arraySign(vector<int> &nums);

int main() {
    vector<int> num1 = {-1, 1, -1, 1, -1};
    std::cout << arraySign(num1) << std::endl;
    return 0;
}

int arraySign(vector<int> &nums) {
    int product = 1;
    for (int i: nums) {
        product *= signFunc(i);
    }
    return product;
}
