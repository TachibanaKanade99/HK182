#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void){
    printk(KERN_INFO "Hello World\n");

    //Return 0 means init_module failed, module can't be loaded.

    return 0;
}

void cleanup_module(void){
    printk(KERN_INFO "Goodbye World\n");
}
