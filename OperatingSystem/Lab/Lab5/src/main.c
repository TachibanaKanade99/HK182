#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
//#include "HelloWorld_Thread.h"
#include "PassArgu_Thread.h"

#define NUM_THREADS 5


int main (){

    int rc;
    int sum = 0;

    for (long t = 0; t < NUM_THREADS; t++){
        printf("In main: creating thread %ld\n", t);

        //Allocate val for thread:
        thread_data_arr[t].thread_id = t;
        thread_data_arr[t].sum = sum++;

        rc = pthread_create(&thread_data_arr[t], NULL, PrintHello, (void *)t);

        //rc will return 0 if success and 1 if fail:
        if (rc){
            printf("Error, return from pthread_create() is %d\n", rc);
            EXIT_FAILURE;
        }
    }
    pthread_exit(NULL);
}