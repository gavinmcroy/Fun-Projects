#include <stdio.h>
#include "allocator.h"

int main() {
    char * test = (char*)malloc(sizeof(char) * 10);
    printf("TEST %c\n",test[1]);
    return 0;
}
