#include <linux/linkage.h>
#include <linux/signal.h>
#include <linux/kernel.h> //include KERN_INFO
#include <linux/mm.h>
#include <linux/uaccess.h> //include copy_to_user

struct proc_segs{
    unsigned long long studentID:
    unsigned long start_code;
    unsigned long end_code;
    unsigned long start_data;
    unsigned long end_data;
    unsigned long start_heap;
    unsigned long end_heap;
    unsigned long start_stack;
};

asmlinkage long sys_procmem(int pid, struct proc_segs *info){
    //TODO: Implement the system call:
    struct task_struct *task;

    for_each_process(task)
    {
        printk("pid = %d | comm = %s\n", task->pid, task->comm);

        if (task->pid == pid)
        {
            if (task->mm != NULL)
            {   
                struct proc_segs user;
                user.studentID = 1752595;
                user.start_code = task->mm->start_code;
                user.end_code = task->mm->end_code;
                user.start_data = task->mm->start_data;
                user.end_data = task->mm->end_data;
                user.start_heap = task->mm->start_brk;
                user.end_heap = task->mm->brk;
                user.start_stack = task->mm->start_stack;

                int result = copy_to_user(info, &user, sizeof(user));

                if (result == 0)
                { 
                    printk("Copy to user successfull!\n");
                }

                else
                {
                    printk("Copy failed\n");
                }
                return 0;
            }
        }
    }
    return -1;
}
