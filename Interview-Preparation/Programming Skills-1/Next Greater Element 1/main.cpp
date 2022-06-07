#include <iostream>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2);


int main() {
    vector<int> nums1 = {1,3,5,2,4};
    vector<int> nums2 = {6,5,4,3,2,1,7};
//    vector<int> nums1 = {4, 1, 2};
//    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> answer = nextGreaterElement(nums1, nums2);
    for (int i: answer) {
        std::cout << i << ", " << std::endl;
    }

    return 0;
}

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    /* Nums1 is subset of Nums2 */
    vector<int> nextGreater;
    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            /* Determine next greater element inside nums 2 after this is true */
            if (nums1[i] == nums2[j]) {
                /* We are on the last element, so just skip since it can't have a next one */
                bool foundSolution = false;
                if (j + 1 >= nums2.size()) {
                    nextGreater.push_back(-1);
                    continue;
                }
                for (int k = j + 1; k < nums2.size(); k++) {
                    if (nums2[k] > nums2[j]) {
                        nextGreater.push_back(nums2[k]);
                        foundSolution = true;
                        break;
                    }
                }
                /* This means no element was found to be greater on the righthand side of the
                 * data struct */
                if (!foundSolution) {
                    nextGreater.push_back(-1);
                }
                /* Easy way of determining a possible solution, because if it didn't run that means
                 * automatically J is the last element, therefore no element can exist to the right of j*/
            }
        }
    }
    return nextGreater;
}

//                if (j + 2 > nums2.size()) {
//                    nextGreater.push_back(-1);
//                    continue;
//                }
//                if (nums2[j + 1] > nums1[i]) {
//                    nextGreater.push_back(nums2[j + 1]);
//                } else {
//                    nextGreater.push_back(-1);
//                }