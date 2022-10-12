#include "allocator.h"

Page segregatedList[LIST_SIZE];

void lib_init() {
    printf("Library opened \n");
    int start = 2;
    for (int i = 0; i < LIST_SIZE; i++) {
        segregatedList[i].size = start;
        start = start << 1;
    }

    for(int i = 0; i < LIST_SIZE; i++){
        printf("%d\n",segregatedList[i].size);
    }
}

void lib_destroy() {
    printf("Library closed \n");
}

void free(void *ptr) {

}

void *malloc(size_t size) {
    /* used for initializing the memory to zero */
    int fd = open("/dev/zero", O_RDWR);

    if(fd == -1){
        exit(ERROR_PD);
    }

    /* ask the OS to map a page of virtual memory initialized to zero
     * initializing makes debugging easier Also page size can be of any memory size */
    void *page = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);

    if(page == MAP_FAILED){
        exit(-1);
    }

    /* LEFT OFF */
    /* The index into our segregated list where we allocate this given page */
    for(int i = 0; i < segregatedList->size; i++){
        if(size <= segregatedList[i].size){
            break;
        }
    }


    /* Storing test data into the page */
    char *pointer = (char *) page;
    for (int i = 0; i < PAGESIZE - 1; i++) {
        pointer[i] = 'a';
    }

    //unmap the page , when you ’re done .
    //munmap(page, PAGESIZE);
    return page;
}