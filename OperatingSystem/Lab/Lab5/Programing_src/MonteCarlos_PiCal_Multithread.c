#include <stdlib.h>
#include <stdio.h>
#include <time.h> // calculate execution time
#include <pthread.h> //All func in pthread return 0 when success and positive nums if failed

#define NUM_THREADS 100

//A function will take num of point as argument:

//Shared variable:
int inCircle = 0;
int points_per_thread;

//Define Mutex:
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//Create thread func:
void* countPoint(void* arg){
    long inCircle_thread = 0;
    int *points_per_thread_ptr = (int *)arg;
    int n = *points_per_thread_ptr;

    srand(time(NULL));
    double x, y, z;

    for (int i = 0; i < n; i++){
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;
        z = x * x + y * y;

        if (z <= 1){
            inCircle_thread++;
        }
    }

    //Lock the mutex to update inCircle:
    pthread_mutex_lock(&mutex);
    inCircle += inCircle_thread;
    pthread_mutex_unlock(&mutex);

    //Exit thread:
    pthread_exit(NULL);
}

int main(int argc, char **argv){

    if (argc < 2){
        printf("Usage: ./MonteCarlos_PiCal_Multithread <number of point>\n");
        exit(1);
    }
    
    //Define pi:
    double pi;
    int n = atoi(argv[1]);
    points_per_thread = n / NUM_THREADS;

    //Create multithread:
    pthread_t threads[NUM_THREADS];

    for (long i = 0; i < NUM_THREADS; i++){
        int rs = pthread_create(&threads[i], NULL, countPoint, &points_per_thread);

        //If rs == 0 success, positive num if failed:
        if (rs != 0){
            printf("Error, return from pthread_create()\n");
            exit(1);
        }
    }

    //Wait until the thread done its work:
    for (int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    //Destroy mutex: does not necessary
    pthread_mutex_destroy(&mutex);

    //Calculating pi:
    pi = (double) inCircle * 4 / n;
    printf("pi = %lf\n", pi);

    //Exit thread:
    pthread_exit(NULL);

    return 0;
}
