#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "Multipro.h"

void multipro(){
    pid_t child_pid;

    child_pid = fork();

    //Check if fork did:
    if (child_pid == -1){
        //printf("child_pid = %d\n", child_pid);
        perror("Fork");
        exit(1);
    }

    if (child_pid == 0){
        //fork succeed, we are inside the child process:
        //printf("child_pid = %d\n", child_pid);
        printf("Hello, ");
        fflush(stdout);
    }
    else
    {
        //fork succeed, we are inside the parent process:
        wait(NULL);
        //printf("parents's_pid = %d\n", child_pid);
        printf("World!\n");
        fflush(stdout);
    }
}