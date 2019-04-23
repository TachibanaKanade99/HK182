#include "findsubstr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void build_PrefixArr(const char *sub, int *prefArr){
    //String length and Substring length:
    int sub_length = strlen(sub);

    //Find Prefix array:
    int length = 0;
    prefArr[0] = 0;

    for (int i = 1; i < sub_length; i++){
        if (sub[i] == sub[length]){
            length = length + 1;
            prefArr[i] = length;
        }
        else
        {
            if (length != 0){
                length = prefArr[length -1];
                i = i - 1;
            }
            else
            {
                prefArr[i] = 0;
            }
            
        }    
    }
}

int find_sub_string(const char *str, const char *sub){
    //Call string length and substring length:
    int str_length = strlen(str);
    int sub_length = strlen(sub);

    //Find prefix array for substring:
    int prefArr[sub_length];
    build_PrefixArr(sub, prefArr);

    //Match substring and string
    int len = 0;
    for (int i = 0; i < str_length; i++){
        if (sub[len] == str[i]){
            len = len + 1;

            if (len == sub_length){
                //stop when reach the end of the substring:
                return 1;
            }
        }

        else
        {
            if (len != 0){
                len = prefArr[len - 1];
                i = i - 1;
            }  
        }
    }
    return -1;
}