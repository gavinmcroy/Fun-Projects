#include <iostream>
#include <sstream>

int subtractProductAndSum(int n);

int main() {
    std::cout<<subtractProductAndSum(4421);
    return 0;
}

int subtractProductAndSum(int n) {
    std::string string = std::to_string(n);
    int sum = 0;
    int product = 1;
    for (char i: string) {
        /* Quick hack to convert a numerical char digit into an int digit */
        sum += (i - '0');
        product *= (i - '0');
    }
    return product - sum;
}
