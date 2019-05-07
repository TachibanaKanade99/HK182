#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "Ex1.h"

_Bool isPowerofTwo(unsigned int num){
    if (num == 0){
        return false;
    }

    return (ceil(log2(num)) == floor(log2(num)));   
}

int HexatoDecimal(char *hex){
    long long decimal = 0;
    int val = 0;

    //Get the length of hexadecimal num:
    int len = strlen(hex);

    for (int i = 0; i < len; i++){
        if (hex[i] >= '0' && hex[i] <= '9'){
            val = hex[i] - 48;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f'){
            val = hex[i] - 97 + 10;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F'){
            val = hex[i] - 65 + 10;
        }

        len = len - 1;
        decimal += val * pow(16, len);
    }
    
    return decimal;
}

void *aligned_malloc(unsigned int size, unsigned int align){

    //Check condition for align:
    if (align <= 0 || !isPowerofTwo(align)){
        printf("In appropriate align\n");
        exit(1);
    }

    //Check condition for size:
    if (size == 0) return NULL;

    //Original block:
    void *p1;
    //Aligned block:
    void **p2;

    //Change size of unsigned int from 32bit to 64bit; the default one is 32 bit:
    uint64_t _size = size;
    uint64_t _align = align;

    //Initialize offset:
    int offset = _align - 1 + sizeof(void*);

    //Allocate memory, if fail return NULL
    p1 = (void*)malloc(_size + offset);
    if (p1 == NULL) return NULL;
    
    p2 = (void **)(((uintptr_t)(p1) + offset) & ~(_align - 1));

    //Since p2 can be considered as the array of void pointer
    // we keep the p1 before p2:
    p2[-1] = p1;

    return p2;
}

void *aligned_free(void *ptr){
    void *p = ((void **)ptr)[-1];
    free(p);
    return NULL;
}