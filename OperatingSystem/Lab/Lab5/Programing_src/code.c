#include <stdio.h>
#include <pthread.h>

//Shared variable:
int current_n = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t number = PTHREAD_COND_INITIALIZER;

void *hello(void *tid) {

    long td = (long) tid;

    pthread_mutex_lock(&mutex);
    while (td > current_n){
        pthread_cond_wait(&number, &mutex);
    }

    printf("Hello from thread %ld\n", td);
    fflush(stdout);
    current_n++;

    pthread_cond_broadcast(&number);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
} 
    
int main() { 
    pthread_t tid[10];
    
    for (long i = 0; i < 10; i++) {
        pthread_create(&tid[i], NULL, hello, (void *)i); 
    }

    //Wait until the thread finish its work:
    for (long i = 0; i < 10; i++){
        pthread_join(tid[i], NULL);
    }

    //Exit thread:
    pthread_exit(NULL);

    return 0;
}