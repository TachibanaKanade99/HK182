#include <linux/module.h> 
// included for all kernel modules

#include <linux/kernel.h> 
// included for KERN_INFO
#include <linux/init.h>

// included for __init and __exit macros
#include <linux/mm.h>

#include <linux/sched.h>
#include <linux/sched.h/signal.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("TUAN");

static int pid = 1;
static int __init procmem_init(void){
    struct task_struct *task;
    printk(KERN_INFO "Starting kernel module!\n");

    // TODO: find task_struct that is associated with the input process pid
    // Hint: use the for_each_process() function:
    for_each_process(task){
        printk("[%d] | [%s]\n", task->pid, task->comm);
        msleep(10);

        if (task->pid == pid){
            printk("Student ID: 1752595\n");

            //check if mm is NULL or not:
            if (task->mm != NULL){
                printk(KERN_INFO "task->mm not null !\n");

                // TODO: show its memory layout
                printk("Code Segment start = [%ul]; end  = [%ul]\n", task->mm->start_code, task->mm->end_code);
                printk("Data Segment start = [%ul]; end  = [%ul]\n", task->mm->start_data, task->mm->end_data);
                printk("Stack Segment start = [%ul]\n", task->mm->start_stack);

                return 0;
            }

            else if (p->active_mm == NULL){
                printk(KERN_INFO "In the thread, using active_mm\n");
            }
        }
    }
    return -1;
}

static void __exit procmem_cleanup(void){
    printk(KERN_INFO "Cleaning up module.\n");
}

module_init(procmem_init);
module_exit(procmem_cleanup);
module_param(pid, int , 0);