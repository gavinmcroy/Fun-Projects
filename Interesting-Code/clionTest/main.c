#include <stdio.h>
#include <stdlib.h>

int main() {
    int* myVal = (int*)malloc(sizeof(int)*20);
    for(int i = 0; i < 20; i++){
        myVal[i] = i;
    }
    int *p = &myVal[7];
    myVal[0] = *(p+4)-10;
    printf("%d",myVal[0]);

    return 0;
}
