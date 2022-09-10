#include <iostream>
#include <vector>

int removeElement(std::vector<int> &nums, int val);

int main() {
    std::vector<int> myVec = {3, 2, 2, 3};
    removeElement(myVec, 3);
    return 0;
}

int removeElement(std::vector<int> &nums, int val) {
    int trueSize = (int) nums.size();
    for (int num : nums) {
        if (num == val) {
            trueSize--;
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == val) {
            /* Take every element and move it in place of trash element */
            for (int j = i; j < nums.size(); j++) {
                if (j + 1 < nums.size()) {
                    nums[j] = nums[j + 1];
                } else {
                    /* Special boundary case */
                    nums[j - 1] = nums[j];
                }
            }
        }
    }
    return trueSize;
}
