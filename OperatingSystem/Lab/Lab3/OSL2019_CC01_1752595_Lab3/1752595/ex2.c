#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    //Create process B:
    int pidB = fork();

    if (pidB == 0){
        wait(NULL);
        //In process B:
        printf("  |_B: pid = %d; ppid = %d\n", getpid(), getppid());

        // create process E:
        int pidE = fork();
        
        if (pidE == 0){
            // In process E:
            printf("    |_E: pid = %d; ppid = %d\n", getpid(), getppid());

            //Create process I:
            int pidI = fork();

            if (pidI == 0){
                //In process I:
                printf("      |_I: pid = %d; ppid = %d\n", getpid(), getppid());
            }

            else
            {
                wait(NULL);
            }
        }

        else
        {   
            wait(NULL);
            int pidF = fork();

            if (pidF == 0){
                // In process F:
                printf("    |_F: pid = %d; ppid = %d\n", getpid(), getppid());
            }

            else
            {
                wait(NULL);
            }
            
        }    
        
    }

    else
    {   
        //Print parent process:
        printf("|_A: pid = %d\n", getpid());
        wait(NULL);

        //create process C:
        int pidC = fork();

        if (pidC == 0){
            //In process C:
            printf("  |_C: pid = %d; ppid = %d\n", getpid(), getppid());

            //create process G:
            int pidG = fork();

            if (pidG == 0){
                printf("    |_G: pid = %d; ppid = %d\n", getpid(), getppid());  
            }

            else
            {
                wait(NULL);
            }
        }

        else
        {   
            wait(NULL);
            //create process D:
            int pidD = fork();
            
            if (pidD == 0){
                //In process D:
                printf("  |_D: pid = %d; ppid = %d\n", getpid(), getppid());
            }
            else
            {
                wait(NULL);
            }   
        }
    }
    return 0;
}