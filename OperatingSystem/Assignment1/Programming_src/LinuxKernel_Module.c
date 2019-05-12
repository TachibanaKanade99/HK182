#include <linux/module.h> 
// included for all kernel modules

#include <linux/kernel.h> 
// included for KERN_INFO
#include <linux/init.h>

// included for __init and __exit macros
#include <linux/mm.h>

#include <linux/sched.h>

static int pid = 1;
static int __init procmem_init(void){
    struct task_struct *task;
    printk(KERN_INFO "Starting kernel module!\n");

    // TODO: find task_struct that is associated with the input process pid
    // Hint: use the for_each_process() function

    // TODO: show its memory layout

    return 0;
}

static void __exit procmem_cleanup(void){
    printk(KERN_INFO "Cleaning up module.\n");
}

module_init(procmem_init);
module_exit(procmem_cleanup);
module_param(pid, int , 0);