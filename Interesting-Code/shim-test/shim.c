#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>

void __attribute__((constructor)) lib_init();

void __attribute__((destructor)) lib_destroy();

int (*original_rand)(void) = NULL;

void lib_init() {
    printf("Initializing Library\n");
    original_rand = dlsym(RTLD_NEXT, "rand");
}

void lib_destroy() {
    printf("Unloading Library\n");
}

int rand(void) {
    return original_rand() % 100;
    //return 45;
}