#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "PassArgu_Thread.h"


void *HelloWorld(void *thread_arg){
    struct thread_data *my_data;
    my_data = (struct thread_data *)thread_arg;
    my_data->message = "Hello World";
    return my_data;
}