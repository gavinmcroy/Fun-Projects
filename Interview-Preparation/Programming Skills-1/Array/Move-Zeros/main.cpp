#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// must be done in place
void moveZeroes(vector<int> &nums);

bool isAllZero(std::vector<int> &elements, int index);

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
    std::vector<int> list3 = {1,2,3,5,6,0,0,0,0};
    //moveZeroes(list2);


   // std::cout<<isAllZero(list3,5)<<std::endl;
   std::cout<<"Hi"<<std::endl;
    //printVector(list2);
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

    for(int i = 0; i < nums.size(); i++){

    }


}

/* Uses zero based indices meaning if indices 0 then 0 is accessing arr[0] */
bool isAllZero(std::vector<int> &elements, int index){
    for(int i = index; i < elements.size(); i++){
        /* Means all elements are not 0 */
        if(elements[i] != 0){
            return false;
        }
    }
    return true;
}

