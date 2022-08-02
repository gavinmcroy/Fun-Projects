#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// must be done in place
void moveZeroes(vector<int> &nums);

//print vector
void printVector(vector<int> &nums) {
    for (int num: nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    std::vector<int> list = {0, 1};
    std::vector<int> list2 = {0, 1, 0, 3, 12};
    moveZeroes(list2);
    printVector(list2);
    return 0;
}

//move all the zeros to the end while maintaining list order
void moveZeroes(vector<int> &nums) {
    int counter = 0;
    //if there is one, just return since you can't do anything with 1
    if (nums.size() <= 1) {
        return;
    }

    for (int num: nums) {
        if (num == 0) {
            counter++;
        }
    }

    //this means the entire list is 0's or that there are no 0's
    if (counter == nums.size() || counter == 0) {
        return;
    }


    //find a 0, check if all other remaining numbers are 0, if not swap until end of list.


}