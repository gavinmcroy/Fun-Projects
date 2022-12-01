//
// Created by gav on 9/29/22.
//

#ifndef REBUILT_MALLOC_ALLOCATOR_H
#define REBUILT_MALLOC_ALLOCATOR_H

#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>

#define _GNU_SOURCE

#define PAGESIZE 4096
#define LIST_SIZE 10
#define ERROR_PD 11

typedef struct Node {
    struct Node *next;
} Node;

typedef struct Page {
    int size;
    char *nextBlock;
    struct Page *nextPage;

} Page;

void __attribute__((constructor)) lib_init();

void __attribute__((destructor)) lib_destroy();


#endif //REBUILT_MALLOC_ALLOCATOR_H
