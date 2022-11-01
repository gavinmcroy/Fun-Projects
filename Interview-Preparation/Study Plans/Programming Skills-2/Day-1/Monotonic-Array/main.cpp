#include <iostream>
#include <vector>

using namespace std;

bool isMonotonic(vector<int> &nums);

int main() {
    vector<int> nums = {1,1,1,1,2,3,4,3};
    std::cout << isMonotonic(nums) << std::endl;
    return 0;
}

bool isMonotonic(vector<int> &nums) {
    /* monotonic means it must be entirely increasing and or decreasing 1,2,3,4,5,6,7 */
    bool isIncreasing = false;
    bool isDecreasing = false;
    /* If there is one element is must be monotonic */
    if (nums.size() < 2) {
        return true;
    }

    /* What if the list is 1,1,1,1,*/
    for (int i = 0; i < nums.size() - 1; i++) {
        int val = nums[i] - nums[i + 1];
        /* if the numbers are the same ignore it, and try again */
        if(val == 0){
            continue;
        }else if(val < 0){
            isIncreasing = true;
        }else {
            isDecreasing = true;
        }

        if(isIncreasing && val > 0){
            return false;
        }
        if(isDecreasing && val < 0){
            return false;
        }
    }
    /* This would hit if the list was all the same number */
    return true;
}
