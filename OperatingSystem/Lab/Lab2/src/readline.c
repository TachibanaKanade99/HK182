#include "readline.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_line(char *str){
    while (fgets(str, 100,  stdin)){
        int i = strlen(str) - 1;
        if (str[i] == '\n'){
            str[i] = '\0';
            return strlen(str);
        }
        else
        {
            return -1;
        }
    }
    
}