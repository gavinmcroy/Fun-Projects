#include <iostream>
#include <vector>
#include <algorithm>

int largestPerimeter(std::vector<int> &nums);

/* A much better solution */
int largestPerimeter1(std::vector<int> &nums);

bool formsTriangle(int a, int b, int c) {
    if (a + b > c && a + c > b && b + c > a) {
        return true;
    } else {
        return false;
    }
}

int main() {
    std::vector<int> num1 = {1, 1, 5, 2, 3};
    std::vector<int> num2 = {1, 2, 1};
    //std::cout << formsTriangle(3, 4, 4) << std::endl;
    std::cout << largestPerimeter(num1) << std::endl;
    std::cout << largestPerimeter1(num1) << std::endl;
    // largestPerimeter(num1);
    std::cout << "Data Size: " << num1.size();
    return 0;
}


int largestPerimeter(std::vector<int> &nums) {
    /* Basically a quick optimizer */
    int largestPerimeter = 0;
    if (nums.size() == 3) {
        if (formsTriangle(nums[0], nums[1], nums[2])) {
            return nums[0] + nums[1] + nums[2];
        } else {
            return 0;
        }
    }

    std::sort(nums.begin(), nums.end(), std::greater<>());
    int iter = 0;
    for (int i = 0; i < nums.size(); i++) {
        /* You know if you 1 from the end no valid solution could exist */
        if (i + 2 > nums.size()) {
            return 0;
        }
            /* Assumes data is sorted, since the first element is the biggest (i) the other two added together
            * must be greater than the largest or else it is not a triangle */
        else if (nums[i] > (nums[i + 1] + nums[i + 2])) {
            continue;
        }
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                iter++;
                if (formsTriangle(nums[i], nums[j], nums[k])) {
                    int tempPerimeter = nums[i] + nums[j] + nums[k];
                    if (tempPerimeter > largestPerimeter) {
                        largestPerimeter = tempPerimeter;
                        std::cout << "a: " << nums[i] << " b: " << nums[j] << " c:" << nums[k] << std::endl;
                        std::cout << "Iterations: " << iter << std::endl;
                        return largestPerimeter;
                    }
                }
            }
        }
    }
    return largestPerimeter;
}

int largestPerimeter1(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end(), std::greater<>());
    for (int i = 0; i < nums.size(); i++) {
        if (i + 2 > nums.size()) {
            return 0;
        } else if (nums[i] > (nums[i + 1] + nums[i + 2])) {
            continue;
        } else if (formsTriangle(nums[i], nums[i + 1], nums[i + 2])) {
            return nums[i] + nums[i + 1] + nums[i + 2];
        }
    }
    return 0;
}
