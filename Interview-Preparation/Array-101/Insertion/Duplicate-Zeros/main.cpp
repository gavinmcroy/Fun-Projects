#include <iostream>
#include <vector>


void duplicateZeros(std::vector<int> &arr);

int main() {
    std::vector<int> testInput = {0, 4, 1, 0, 0, 8, 0, 0, 3};
    /* {1, 0, 2, 3, 0, 4, 5, 1} */
    /* Fails on [0,4,1,0,0,8,0,0,3] */
    duplicateZeros(testInput);
    for (int i : testInput) {
        std::cout << i << " ";
    }
    return 0;
}

void duplicateZeros(std::vector<int> &arr) {
    /* insert,push all elements forward, remove excessive */
    for (int i = 0; i < arr.size();) {
        /*  There is no more possible duplicates */
        if (i + 2 > arr.size()) {
            break;
        }
        /* We found our 0 */
        if (arr[i] == 0) {
            //{1, 0, 2, 3, 3, 4, 5, 1}
            /* Since we are duplicating a 0 one ahead we need to ensure this duplicate is not rechecked*/
            int temp = 0;
            int temp2 = 0;
            bool duplicateOnce = true;
            for (int j = 0; j < arr.size() - i; j++) {
                /* Creates the double 0 */
                if (duplicateOnce) {
                    /* current */
                    /* Variable one ahead */
                    temp = arr[i + j + 1];
                    arr[i + j + 1] = 0;
                    /* i is incremented by two because 0 0 1 <- */
                    i += 2;
                    /* The continued at the end causes j to increment when it shouldn't */
                    j--;
                    duplicateOnce = false;
                    continue;
                }
                temp2 = arr[i + j];
                arr[i + j] = temp;
                temp = temp2;
            }
        } else {
            i++;
        }
    }
}

//---Out of place operation
//void duplicateZeros(std::vector<int> &arr) {
//    std::vector<int> newVec;
//    for (int i = 0; i < arr.size(); i++) {
//        if (newVec.size() == arr.size()) {
//            break;
//        }
//        if (arr[i] == 0) {
//            newVec.push_back(arr[i]);
//            newVec.push_back(arr[i]);
//        } else {
//            newVec.push_back(arr[i]);
//        }
//    }
//    std::cout << "[";
//    for (int i = 0; i < newVec.size(); i++) {
//        if (i == newVec.size() - 1) {
//            std::cout << newVec[i];
//        } else {
//            std::cout << newVec[i] << ",";
//        }
//
//    }
//    std::cout << "]";
//}