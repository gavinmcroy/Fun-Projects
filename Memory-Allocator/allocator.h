//
// Created by parallels on 11/4/21.
//

#ifndef PLEASE_WORK_ALLOCATOR_H
#define PLEASE_WORK_ALLOCATOR_H

void __attribute__ ((constructor)) shimInit(void);

void __attribute__ ((destructor)) cleanup(void);

typedef struct memory_t {
    struct memory_t *next;
    void *data;
}memory_t;

typedef struct page_t {
    struct page_t *next;
    memory_t *freeList;
    memory_t *usedList;
    int blockSize;
}page_t;

page_t *newPage(page_t *prev, int size);

__attribute__((unused)) memory_t *newMemBlock(page_t *page, int size);

page_t *newLargePage(page_t *prev, int size);

/* array to hold page list heads */
page_t *lists[11];
int fd;

#endif //PLEASE_WORK_ALLOCATOR_H
