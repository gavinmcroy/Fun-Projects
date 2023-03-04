#include <stdio.h>

int main() {
    int i[10];
    int c[12];

    for(int x = 0; x < 10; x++){
        i[x] = x;
    }
    for(int j = 0; j < 12; j++){
        c[j] = j;
    }
    int *pi = &i[5];
    pi+=6;
    //printf("%X\n",*pi);

    printf("Hello, World!\n");

    int uc = 0x4F & 0x14 | 0xF2;
    printf("%X",uc);
    return 0;
}
