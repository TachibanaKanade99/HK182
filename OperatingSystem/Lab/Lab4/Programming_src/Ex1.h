#ifndef EX1_H
#define EX1_H

//This function is used to check if align is power of two:
_Bool isPowerofTwo(unsigned int num);

//This function converts hexadecimal into decimal val:
int HexatoDecimal(char *hex);

void *aligned_malloc(unsigned int size, unsigned int align);

void *aligned_free(void *ptr);

#endif