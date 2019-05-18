#include <procmem.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdint.h>
#include <stdlib.h> 

int main(int argc, char **argv) {  
    struct proc_segs info;

    if (argc < 2){
        printf("Please input the pid as a command line argument!\n");
    }

    else{
        pid_t mypid = (pid_t) atoi(argv[1]);
        printf("pid = %d\n", (int) mypid);
    
    //     if (procmem(mypid, &info) == 0){ 
    //         printf("Student ID: %lu \n", info.studentID); 
    //         printf("Code segment: 0x%lx-0x%lx\n", info.start_code, info.end_code); 
    //         printf("Data segment: 0x%lx-0x%lx\n", info.start_data, info.end_data); 
    //         printf("Heap segment: 0x%lx-0x%lx\n", info.start_heap, info.end_heap); 
    //         printf("Start stack: 0x%lx\n", info.start_stack); 
    //     } 
        
    //     else{ 
    //         printf("Cannot get information from the process %d\n", mypid); 
    //     } 
            
    //         // If necessary, uncomment the following line to make this program run 
    //         // long enough so that we could check its maps file 
    //         //sleep(100); 
    }

    return 0;
}
