#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    int b[20];
    for(int i =0; i < 20; i++){
        b[i] = i;
    }

    int i  = 0x45318351;
    short int *ptr = (short int *) &i;
    *ptr = 3950;
    int * p = &b[-17] - 4;

    std::cout<<p<<std::endl;
    std::cout<<i<<std::endl;
    return 0;
}
