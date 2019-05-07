#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
#include "Ex1.h"


int main(){
    
    unsigned int size, align;
    printf("Input size and align: \n");
    scanf("%ud", &size);
    scanf("%ud", &align);

    void *p = aligned_malloc (size, align);

    printf ("%p\n", p);

    if (HexatoDecimal((char *)p) % align == 0){
        printf("Valid\n");
    }

    aligned_free (p);

    printf("\n");
    printf("Size of uintptr_t: %ld\n", sizeof(uintptr_t));
    printf("Size of unsigned integer: %ld\n", sizeof(unsigned int));
    printf("Size of size_t: %ld\n", sizeof(size_t));


    return 0;
}