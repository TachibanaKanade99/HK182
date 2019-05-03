#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "getPID.h"
#include "create_pro.h"
#include "Multipro.h"
#include "pro_info.h"
#include "Ex3.h"

int value = 5;
int main(){
    //Get process's ID, parent's ID, group's number:
    // getPID();
    // printf("\n");

    //Create process using fork:
    // for (int i = 0; i < 2; i++){
    //     fork();
    //     create_pro();
    // }

    //Run multipro():
    //multipro();

    //Run pro_info():
    //pro_info();

    //Run Ex3
    //Ex3();

    pid_t pid;
    pid = fork();
    if (pid == 0){
        value += 15;
        return 0;
    }

    else if (pid > 0){
        wait(NULL);
        printf("PARENT: value = %d", value);
        return 0;
    }
}