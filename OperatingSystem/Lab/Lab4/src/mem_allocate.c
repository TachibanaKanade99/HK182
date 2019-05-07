#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mem_allocate.h"

void mem_allocate(){
    size_t MB = 1024 * 1024;
    size_t maxMB = 0;

    void *ptr = NULL;

    maxMB += 2 * MB;
    ptr = malloc(maxMB);

    if (ptr != NULL){
        printf("Bytes of memory checked = %zi\n", maxMB);
        memset(ptr, 0, maxMB); // fille the allocated region
    }
    
    free(ptr);
}