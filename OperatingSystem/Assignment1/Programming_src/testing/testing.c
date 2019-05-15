#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>
#define SIZE 100

int main(){
    long sysvalue;
    unsigned long info[SIZE];
    sysvalue = syscall(377, 1, info);
    printf("My student ID: %lu\n", info[0]);
    
    return 0;
}