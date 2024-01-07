#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

// static char *whom = "world";
// module_param(whom, charp, 0644);
// MODULE_PARM_DESC(whom, "Recipient of the hello message");


// static int howmany = 1;
// module_param(howmany, int, 0644);
// MODULE_PARM_DESC(howmany, "Number of greetings");

static int __init hello_init(void)
{
    printk(KERN_ALERT "Hello, world\n");
    return 0;
}

static void __init hello_exit(void)
{
    printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);


module_param(
    name, /* name of an already defined variable */
    type, /* standard types (different from C types) are:
    * byte, short, ushort, int, uint, long, ulong
    * charp: a character pointer
    * bool: a bool, values 0/1, y/n, Y/N.
    * invbool: the above, only sense-reversed (N = true). */
    perm /* for /sys/module/<module_name>/parameters/<param>,
    * 0: no such module parameter value file */
);

/* Example: drivers/block/loop.c */
// static int max_loop;
// module_param(max_loop, int, 0444);
// MODULE_PARM_DESC(max_loop, "Maximum number of loop devices");


