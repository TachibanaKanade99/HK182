#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "Ex3.h"

int val = 5;

int Ex3(){
    pid_t pid;
    pid = fork();
    if (pid == 0){
        val += 15;
        return 0;
    }

    else if (pid > 0){
        wait(NULL);
        printf("PARENT: value = %d", val);
        return 0;
    }
}