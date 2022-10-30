#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool containsDuplicate(vector<int>& nums);

int main() {
    std::vector<int> nums = {1,2,3,4,5,6,7,8,9,20};
    std::cout<<containsDuplicate(nums);
    return 0;
}

bool containsDuplicate(vector<int>& nums){
    std::map<int,int> map1;

    for(int i = 0; i < nums.size(); i++){
        /* Count the occurrences of any number */
        map1[nums[i]]++;
    }

    for(int i = 0; i < nums.size(); i++){
        if(map1[nums[i]] > 1){
            return true;
        }
    }

    return false;

}
