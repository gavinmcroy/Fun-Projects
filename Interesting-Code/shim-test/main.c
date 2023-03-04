#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int main() {
    printf("Hello, World!\n");
    //char *environment = "DYLD_INSERT_LIBRARIES";
    //setenv(environment,"")
    //execve(environment,)
    printf("%d\n", rand());
    return 0;
}

//DYLD_INSERT_LIBRARIES=$PWD/shim.dylib DYLD_FORCE_FLAT_NAMESPACE=1 ./mallocTest
