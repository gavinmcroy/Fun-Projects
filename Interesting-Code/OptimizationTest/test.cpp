
#include <iostream>

int main(){
    double x = 100000.53232;
    for(int i = 0; i < 1000000000; i++){
        x*=2;
    }
    printf("%lf",x);
    return 0;
}
