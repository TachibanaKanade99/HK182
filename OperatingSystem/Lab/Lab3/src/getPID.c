#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "getPID.h"

void getPID(){
    printf("Process_ID: %d\n", getpid());
    printf("Parent_ID: %d\n", getppid());
    printf("My_group: %d\n", getpgrp());
}