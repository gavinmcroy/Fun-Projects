#include <iostream>

int countOdds(int low, int high);

int main() {
    std::cout<<countOdds(14,17);
}

int countOdds(int low, int high) {
    int solution = 0;
    if(abs(low - high) == 1 ){
        return 1;
    }
    /* Both are odd */
    if(low % 2 == 1 && high % 2 == 1){
        solution = abs(low - high) / 2 + 1;
    } /* Low is even and high is odd */
    else if(low % 2 == 0 && high % 2 == 1){
        solution = abs(low - high) / 2 + 1;
    } /* Both are even */
    else if(low % 2 == 0 && high % 2 == 0){
        solution = abs(low-high) / 2;
    } /* Low is odd and high is even*/
    else{
        solution =  abs(low-high) / 2+1;
    }
    return solution;
}
