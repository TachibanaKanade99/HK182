#include "findsubstr.h"
#include "readline.h"
#include <stdio.h>

int main(int argc, char *argv[]){

    //Implement mygrep:
    char *sub = argv[1];

    char str[101];

    //Open file:
    while (!feof(stdin)){
        read_line(str);
        //printf("%s%s%s\n", str, " ", sub);
        //printf("%d\n", find_sub_string(str, sub));
        if (find_sub_string(str, sub) == 1){
            printf("%s\n", str);
        }
    }

    return 0;
}