#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "HelloWorld_Thread.h"


void *PrintHello(void *threadid){
    long tid;
    tid = (long)threadid;

    printf("Hello World! It's me, thread %ld\n", tid);
    pthread_exit(NULL);
}