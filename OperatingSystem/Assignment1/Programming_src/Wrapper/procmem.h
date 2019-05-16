#ifndef _PROC_MEM_H_
#define _PROC_MEM_H_
#include <unistd.h>
#include <sys/types.h>

struct proc_segs;
long sys_procmem(pid_t pid, struct proc_segs *info);

#endif // _PROC_MEM_H_