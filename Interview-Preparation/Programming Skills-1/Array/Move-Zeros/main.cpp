#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// must be done in place
void moveZeroes(vector<int> &nums);

bool isAllZero(std::vector<int> &elements);

//print vector
void printVector(vector<int> &nums) {
    for (int num: nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    std::vector<int> list = {0, 1};
    std::vector<int> list2 = {0, 1, 3, 0, 0};
    std::vector<int> list3 = {0,0,1};
    std::vector<int> list4 = {1,1,1,1,1,1,1,1,1,1,1,0};
    moveZeroes(list3);

    //std::cout<<isAllZero(list4)<<std::endl;

    printVector(list3);
    return 0;
}

/* move all the zeros to the end while maintaining list order */
void moveZeroes(vector<int> &nums) {
    int counter = 0;
    /* if there is one element, just return since you can't do anything with 1 */
    if (nums.size() <= 1) {
        return;
    }

    /* How many 0's there are */
    for (int num: nums) {
        if (num == 0) {
            counter++;
        }
    }

    /* this means the entire list is 0's or that there are no 0's */
    if (counter == nums.size() || counter == 0) {
        return;
    }

    /* Loop until all elements at the end contain 0, each time we encounter a 0 that isn't
     * in the correct place, swap until it is, then restart the index */
    int index = 0;
    while (!isAllZero(nums)) {
        /* Need a special case for when 0 is already at the end */

        /* if we find a 0 and the remaining list is NOT all 0, swap */
        if (nums[index] == 0) {
            //swap until we reach the last element
            int anotherIndex = index;
            while (anotherIndex < nums.size()-1) {
                swap(nums[anotherIndex], nums[anotherIndex + 1]);
                anotherIndex++;
            }
        }else{
            index++;
        }

    }


}

/* Uses zero based indices meaning if indices 0 then 0 is accessing arr[0] */
bool isAllZero(std::vector<int> &elements) {
    bool allZero = false;
    for (int i = 0; i < elements.size(); i++) {
        /* Means all elements are not 0, after the first 0 */
        if(allZero && elements[i] !=0 ){
            return false;
        }

        if (elements[i] == 0) {
            allZero = true;
        }
    }
    return true;
}

