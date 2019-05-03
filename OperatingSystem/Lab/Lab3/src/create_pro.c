#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "create_pro.h"

void create_pro(){
    switch (fork()){
        case 0: 
            printf("I am the child: pid= %d\n", getpid());
            break;
        default:
            printf("I am the parents: pid= %d\n", getppid());
            break;
        case -1:
            printf("Fork failed");
    }
}