#define _GNU_SOURCE

#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "allocator.h"


#define PAGESIZE 4096

void shimInit(void) {
    fd = open("/dev/zero", O_RDWR);
}

page_t *newLargePage(page_t *prev, int size) {
    page_t *newPage = NULL;

    newPage = mmap(NULL, (size + 32),
                   PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);

    if (newPage == (page_t *) -1) perror("MMAP FAIL"); //make sure page map works

    if (prev) {
        prev->next = newPage;
    }
    newPage->next = NULL;

    newPage->usedList = NULL;
    newPage->blockSize = size;

    newPage->freeList = (memory_t *) ((char *) newPage + sizeof(page_t));

    memory_t *currentBlock = newPage->freeList;
    currentBlock->data = (void *) ((char *) currentBlock + sizeof(memory_t)); //set up data pointer.
    currentBlock->next = NULL;

    return newPage;

}

void *malloc(size_t size) {
    if (size <= 0) {
        return NULL;
    }

    int blockSize;
    page_t *localPage = NULL;
    memory_t *memoryBlock = NULL;

    /* Determine which list is going to be used */
    int listNumberUsed = 0;
    if (size <= 1024) {
        if (size <= 2) {
            listNumberUsed = 1;
        } /* size 4 */
        else if (size > 2 && size <= 4) {
            listNumberUsed = 2;
        }/* size 8 */
        else if (size > 4 && size <= 8) {
            listNumberUsed = 3;
        }/* size 16 */
        else if (size > 8 && size <= 16) {
            listNumberUsed = 4;
        }/* size 32 */
        else if (size > 16 && size <= 32) {
            listNumberUsed = 5;
        }/* size 64 */
        else if (size > 32 && size <= 64) {
            listNumberUsed = 6;
        }/* size 128 */
        else if (size > 64 && size <= 128) {
            listNumberUsed = 7;
        } /* size 256 */
        else if (size > 128 && size <= 256) {
            listNumberUsed = 8;
        } /* size 512 */
        else if (size > 256 && size <= 512) {
            listNumberUsed = 9;
        } /* size 1024*/
        else {
            listNumberUsed = 10;
        }

        blockSize = 1 << (listNumberUsed);

        /* check list for space. */
        if (!lists[listNumberUsed]) { /* no pages initially. */
            lists[listNumberUsed] = newPage(NULL, blockSize);
            localPage = lists[listNumberUsed];
        } else { /* pages initially present. */
            localPage = lists[listNumberUsed];
            while (localPage->next != NULL && localPage->freeList == NULL) {
                localPage = localPage->next;
            }
            /* if free list and next page is null, then we need another page */
            if (localPage->next == NULL && localPage->freeList == NULL) {
                localPage->next = newPage(localPage, blockSize);
                localPage = localPage->next;
            }
        }

        /* No issue if its only thing in list, it will be left null */
        localPage->freeList = localPage->freeList->next;
        /* page should be here, Remove from free list */
        memoryBlock = localPage->freeList;

        localPage->usedList = memoryBlock;
        /* add to front of used list */
        memoryBlock->next = localPage->usedList;

        return memoryBlock->data;

    } /* Allocations of 1024 or more */
    else {
        blockSize = size;
        /* Does our free list have space (null means empty, AKA no more memory) */
        if (!lists[listNumberUsed]) {
            /* Create a big page */
            lists[listNumberUsed] = newLargePage(NULL, blockSize);
            localPage = lists[listNumberUsed];
        } else {
            localPage = lists[listNumberUsed];
            while (localPage->next) {
                localPage = localPage->next;
            }
            /* Probably need a  new page every time */
            localPage->next = newLargePage(localPage, blockSize);
            localPage = localPage->next;
        }
        memoryBlock = localPage->freeList;
        /* add to front of used list */
        localPage->usedList = memoryBlock;
        /* in large pages, there's only one object */
        localPage->freeList = NULL;
        return memoryBlock->data;
    }
}

void *calloc(size_t nmemb, size_t size) {
    unsigned int totalSize = nmemb * size;
    void *returnPointer = malloc(totalSize);
    /* Set everything to 0 */
    memset(returnPointer, 0, totalSize);
    return returnPointer;
}

void free(void *ptr) {
    /* Why would anyone do this */
    if (!ptr) {
        return;
    }

    /* Horrible bit math to get the page containing the memory_t. Gross */
    page_t *page = (page_t *) ((uintptr_t) ptr & ((uintptr_t) 0xFFFFFFFFFFFFF000));

    memory_t *current = (memory_t *) &page->usedList;
    memory_t *previous = NULL;
    /* Find the correct block */
    while (current->data != ptr) {
        previous = current;
        if (current->next) {
            current = current->next;
        }
    }

    /* Lets remove it from the used list <front> */
    if (!previous) {
        page->usedList = current->next;
    } /* <middle >*/
    else if (current->next) {
        previous->next = current->next;
    } /* <end of list> */
    else {
        previous->next = NULL;
    }

    current->next = page->freeList;
    page->freeList = current;

    /* Insurance policy to set to 0 */
    if (page->blockSize < 4096) {
        memset(current->data, 0, page->blockSize);
    }

    /* find an empty page and unmap that bad boy */
    if (page->usedList) {
        int listNum, isHead = 0;

        if (page->blockSize > 1024) {
            listNum = 0;
        } else if (page->blockSize == 2) {
            listNum = 1;
        } else if (page->blockSize == 4) {
            listNum = 2;
        } else if (page->blockSize == 8) {
            listNum = 3;
        } else if (page->blockSize == 16) {
            listNum = 4;
        } else if (page->blockSize == 32) {
            listNum = 5;
        } else if (page->blockSize == 64) {
            listNum = 6;
        } else if (page->blockSize == 128) {
            listNum = 7;
        } else if (page->blockSize == 256) {
            listNum = 8;
        } else if (page->blockSize == 512) {
            listNum = 9;
        }
            /* Size 1024*/
        else {
            listNum = 10;
        }

        /* Means we found the head */
        if (page == lists[listNum]) {
            isHead = 1;
        }

        /* identify previous node if not head. */
        page_t *current1 = NULL;
        page_t *previous1 = NULL;
        if (!isHead) {
            current1 = lists[listNum];
            while (current1 != page && current1 != NULL) {
                previous1 = current1;
                current1 = current1->next;
            }
            previous1 = current1;
        }

        if (isHead) {
            lists[listNum] = page->next; //advance
        } else if (page->next != NULL) { //middle of list
            previous1->next = page->next;
        } else {
            previous1->next = NULL; //end of list
        }

        /* list management is done. Remove the page node.*/
        munmap(page, page->blockSize);
    }
}

page_t *newPage(page_t *prev, int size) {
    page_t *newPage = NULL;

    newPage = mmap(NULL, PAGESIZE,
                   PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);

    if (newPage == (page_t *) -1) {
        perror("MMAP FAIL"); //make sure page map works
    }
    if (prev) {
        prev->next = newPage;
    }

    newPage->next = NULL;
    /* set up node */
    newPage->usedList = NULL;
    newPage->blockSize = size;

    /* set up free list */
    unsigned int needed = sizeof(memory_t) + size;
    int remaining = PAGESIZE - sizeof(page_t);


    newPage->freeList = (memory_t *) ((char *) newPage + sizeof(page_t));

    memory_t *currentBlock = newPage->freeList;
    currentBlock->data = (void *) ((char *) currentBlock + sizeof(memory_t)); //set up data pointer.

    memory_t *previousBlock = currentBlock;

    while (remaining >= needed) {
        memory_t *newBlock = NULL;
        newBlock = (memory_t *) ((char *) previousBlock + sizeof(memory_t) + size);
        newBlock->data = (void *) ((char *) newBlock + sizeof(memory_t));
        previousBlock->next = newBlock;
        newBlock->next = NULL;

        remaining -= needed;
    }


    return newPage;
}


void *realloc(void *ptr, size_t size) {
    void *newLocation = ptr;
    if (!ptr) {
        return malloc(size);
    } else if (size != 0) {
        page_t *page = (page_t *) ((uintptr_t) ptr & ((uintptr_t) 0xFFFFFFFFFFFFF000));
        int currentSize = page->blockSize;
        if (size > currentSize) {
            newLocation = malloc(size);
            memcpy(newLocation, ptr, currentSize);
        } /* don't know what to do otherwise...*/
    }
    return newLocation;
}
