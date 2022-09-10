#include <iostream>
#include <vector>


void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n);

int main() {
    std::vector<int> nums1 = {4, 0, 0, 0, 0, 0};
    std::vector<int> nums2 = {1, 2, 3, 5, 6};
    merge(nums1, 1, nums2, 5);
    for (int x : nums1) {
        std::cout << x << " ";
    }
    return 0;
}

//[1,2,3,0,0,0], m = 3, nums2 = [2,5,6]
void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {

}



/* Special case for when nums2 is empty */
//    if (n == 0) {
//        return;
//    }
//    /* Special case when nums1 is empty */
//    if (m == 0) {
//        for (int i = 0; i < n; i++) {
//            nums1[i] = nums2[i];
//        }
//        return;
//    }
//    /* Another special case for when all elements in nums1 are less than nums2*/
//    if (nums1[m - 1] < nums2[0]) {
//        for (int i = 0; i < n; i++) {
//            nums1[m + i] = nums2[i];
//        }
//        return;
//    }
//
//    /* Special case for when every element in nums1 is greater than nums2 */
//    if (nums1[0] > nums2[n - 1]) {
//        for (int i = 0; i < n; i++) {
//            /* If an element in nums1 is greater than nums2 */
//            if (nums1[i] > nums2[i]) {
//                int temp = nums1[i];
//                nums1[i] = nums2[i];
//                nums1[m + i] = temp;
//            }
//            /*  */
//        }
//        return;
//    }
//
//    //    int secondArrayCounter = 0;
//    //    for (int i = 0; i < m + n; i++) {
//    //        /* if the current element is less than the first of num2 than skip */
//    //        if (nums1[i] < nums2[secondArrayCounter]) {
//    //            continue;
//    //        }
//    //        /* The elements are equal */
//    //       // else if()
//    //        /* An if the element is not less than, it needs to be moved */
//    //        else {
//    //            int temp = nums1[i+1];
//    //            /* Step the second array to another element */
//    //
//    //            nums1[i] = nums2[secondArrayCounter];
//    //            /* Take the element replaced and put it on the end */
//    //            secondArrayCounter++;
//    //        }
//    //    }
//    int safeCounter = m;
//    for (int i = 0; i < m; i++) {
//        /* The element in front is larger, therefore move it back */
//        for (int j = 0; j < n; j++) {
//            if (nums1[i] > nums2[j]) {
//                int temp = nums1[i];
//                nums1[i] = nums2[j];
//                nums1[i + 1] = temp;
//                safeCounter++;
//            } /* This will catch the extra elements at the end [1 2 3] [2 5 6] such as 5 and 6 as 3 is always < then both  */
//            else if (i == m - 1) {
//                nums1[safeCounter] = nums2[j];
//                safeCounter++;
//            }
//        }
//    }
//}
//
/////* We are merging nums2 into nums1 */
////int safeCounter = m;
////if (m == 0) {
////    nums1[0] = nums2[0];
////    return;
////}
////if (n == 0) {
////    return;
////}
////
////for (int i = 0; i < m; i++) {
////    /* The element in front is larger, therefore move it back */
////    for (int j = 0; j < n; j++) {
////        if (nums1[i] > nums2[j]) {
////            int temp = nums1[i];
////            nums1[i] = nums2[j];
////            nums1[i + 1] = temp;
////            safeCounter++;
////        } /* This will catch the extra elements at the end [1 2 3] [2 5 6] such as 5 and 6 as 3 is always < then both  */
////        else if (i == m - 1) {
////            nums1[safeCounter] = nums2[j];
////            safeCounter++;
////        }
////    }
////}