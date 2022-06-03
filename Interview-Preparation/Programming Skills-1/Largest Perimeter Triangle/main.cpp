#include <iostream>
#include <vector>
#include <limits>

int largestPerimeter(std::vector<int> &nums);

bool formsTriangle(int a, int b, int c) {
    if (a + b > c && a + c > b && b + c > a) {
        return true;
    } else {
        return false;
    }
}

int main() {
    std::vector<int> num1 = {3,4,15,2,9,4};
    std::vector<int> num2 = {1, 2, 1};
    std::cout << formsTriangle(2, 1, 2) << std::endl;
    std::cout << largestPerimeter(num1);
    return 0;
}


int largestPerimeter(std::vector<int> &nums) {
    /* Basically a quick optimizer */
    int largestPerimeter = 0;
    if (nums.size() == 3) {
        if (formsTriangle(nums[0], nums[1], nums[2])) {
            return nums[0] + nums[1] + nums[2];
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            int a = nums[i];
            if (j + 1 >= nums.size()) {
                continue;
            }
            int b = nums[j];
            int c = nums[j + 1];

            /* We need a boundary case to prevent exceeding array limit */

            if (formsTriangle(a, b, c)) {
                if (a + b + c > largestPerimeter) {
                    largestPerimeter = a + b + c;
                }
            }
        }
    }
    return largestPerimeter;
}
