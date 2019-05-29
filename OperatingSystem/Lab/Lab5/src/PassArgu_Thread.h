#ifndef PASSARGU_THREAD_H
#define PASSARGU_THREAD_H
#define NUM_THREADS 5

struct thread_data
{
    int thread_id;
    int sum;
    char *message;
};

struct thread_data thread_data_arr[NUM_THREADS];

void *PrintHello(void *thread_arg);


#endif