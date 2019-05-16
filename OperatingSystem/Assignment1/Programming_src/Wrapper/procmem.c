#include "procmem.h"
#include <linux/kernel.h>
#include <sys/syscall.h>

struct proc_segs{
    unsigned long studentID;
    unsigned long start_code;
    unsigned long end_code;
    unsigned long start_data;
    unsigned long end_data;
    unsigned long start_heap;
    unsigned long end_heap;
    unsigned long start_stack;
};

long procmem(pid_t pid, struct proc_segs *info){
    //TODO: implement the wrapper here:
    long sysvalue;
    sysvalue = syscall(377, pid, info);

    return sysvalue;
}