#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX 1000

int main() {
    //create array and count:
    int arr[MAX];
    int size = 0;
    int count = 0;

    FILE *file = fopen("numbers.txt", "rb");
    if (file == NULL){
        printf("Unable to read file\n");
        exit(1);
    }

    while(!feof(file)){
        char str[100];
        for(int i = 0; i < MAX; i++){
            if (fgets(str, 100, file) != NULL){
                arr[i] = atoi(str);
                size = size + 1;
            }
        }
    }
    fclose(file);

    //Create process:
    pid_t pid;
    pid = fork();

    if (pid == -1){
        printf("Cannot create process\n");
        exit(1);
    }

    else if (pid == 0) // In child process:
    {
        for (int i = 0; i < size; i++){
            if (arr[i] % 3 == 0){
                count = count + 1;
            }
        }

        //Print count:
        printf("Count for child process: %d\n", count);
    }

    else
    {
        //In parent process:
        for (int i = 0; i < size; i++){
            if (arr[i] % 2 == 0){
                count = count + 1;
            }
        }

        //Print count:
        printf("Count for parent process: %d\n", count);
    }
    
    return 0;
}