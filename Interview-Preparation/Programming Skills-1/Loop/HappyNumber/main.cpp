#include <iostream>
#include <cmath>

bool isHappy(int n);


int main() {
    std::cout << isHappy(1999999999) << std::endl;
    return 0;
}

bool isHappy(int n) {
    /* Step one is break a number down to its square */
    /* Convert n into a string */
    int sum = 0;
    int start = 0;
    while (true) {
        std::string number = std::to_string(n);
        /* Interesting bug, can't assume the number is two digits, so add up all digits */
        for (int i = 0; i < number.size(); i++) {
            sum += (number[i] - '0') * (number[i] - '0');
        }
        /* if the sum isn't 1, then we haven't found a happy number yet */
        if (sum != 1) {
            n = sum;
            sum = 0;
        } else {
            return true;
        }
        /* Stops after 10 attempts at finding happy number */
        if (start == 10) {
            return false;
        }
        start++;
    }
}