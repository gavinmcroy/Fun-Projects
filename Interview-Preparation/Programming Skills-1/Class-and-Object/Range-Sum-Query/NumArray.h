//
// Created by Gavin T McRoy on 10/30/2022.
//

#ifndef RANGE_SUM_QUERY_NUMARRAY_H
#define RANGE_SUM_QUERY_NUMARRAY_H

#include <vector>

using namespace std;

class NumArray {
private:
    std::vector<int> numList;

public:
    NumArray(vector<int>& nums) {
        numList = nums;
    }

    int sumRange(int left, int right) {
        int sum = 0;
        for(int i = left; i <= right; i++){
            sum+=numList[i];
        }
        return sum;
    }
};


#endif //RANGE_SUM_QUERY_NUMARRAY_H
