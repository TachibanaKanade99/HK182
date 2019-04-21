#include "findsubstr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_sub_string(const char *str, const char *sub){
    //String length and Substring length:
    int str_length = strlen(str);
    int sub_length = strlen(sub);

    //Find Prefix array:
    int length = 0;
    int prefArr[sub_length];
    prefArr[0] = 0;

    for (int i = 1; i < sub_length; i++){
        if (sub[i] == sub[length]){
            length = length + 1;
            prefArr[i] = length;
        }
        else
        {
            if (length != 0){
                length = prefArr[length -1 ];
                i = i - 1;
            }
            else
            {
                prefArr[i] = 0;
            }
            
        }
        
    }

    //Match substring and string
    int len = 0;
    for (int i = 0; i < str_length; i++){
        if (sub[len] == str[i]){
            len = len + 1;

            if (i == sub_length - 1 || i == str_length - 1){
                //reach the end of string or substring:
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