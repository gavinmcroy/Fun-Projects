#include <iostream>
#include "NumArray.h"

int main() {
    std::vector<int> numList = {-2, 0, 3, -5, 2, -1};
    NumArray * numArray = new NumArray(numList);
    std::cout<<numArray->sumRange(0,5);
    return 0;
}
