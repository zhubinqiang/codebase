#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/device.h>

#define DEVICE_NAME "mychardev"
#define CLASS_NAME "chardev"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple character device driver");
MODULE_VERSION("0.1");

static int majorNumber;
static char message[256] = {0};
static short size_of_message;
static struct class* charClass = NULL;
static struct device* charDevice = NULL;

// 声明文件操作函数
static int dev_open(struct inode *inodep, struct file *filep){
   printk(KERN_INFO "Device opened\n");
   return 0;
}

static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset){
   int err_count = 0;
   err_count = copy_to_user(buffer, message, size_of_message);
   if(err_count==0){
      printk(KERN_INFO "Sent %d characters to the user\n", size_of_message);
      return (size_of_message=0);
   }
   else {
      printk(KERN_INFO "Failed to send %d characters to the user\n", err_count);
      return -EFAULT;
   }
}

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset){
   sprintf(message, "%s", buffer);
   size_of_message = strlen(message);
   printk(KERN_INFO "Received %zu characters from the user\n", len);
   return len;
}

static int dev_release(struct inode *inodep, struct file *filep){
   printk(KERN_INFO "Device closed\n");
   return 0;
}

// 定义文件操作结构体
static struct file_operations fops = {
   .open = dev_open,
   .read = dev_read,
   .write = dev_write,
   .release = dev_release,
};

// 初始化模块
static int __init chardev_init(void){
   printk(KERN_INFO "CharDev: Initializing the CharDev LKM\n");
   // 分配主设备号
   majorNumber = register_chrdev(0, DEVICE_NAME, &fops);
   if (majorNumber<0){
      printk(KERN_ALERT "CharDev failed to register a major number\n");
      return majorNumber;
   }
   printk(KERN_INFO "CharDev: registered correctly with major number %d\n", majorNumber);

   // 注册设备类
   charClass = class_create(THIS_MODULE, CLASS_NAME);
   if (IS_ERR(charClass)){
      unregister_chrdev(majorNumber, DEVICE_NAME);
      printk(KERN_ALERT "Failed to register device class\n");
      return PTR_ERR(charClass);
   }
   printk(KERN_INFO "CharDev: device class registered correctly\n");

   // 注册设备驱动
   charDevice = device_create(charClass, NULL, MKDEV(majorNumber, 0), NULL, DEVICE_NAME);
   if (IS_ERR(charDevice)){
      class_destroy(charClass);
      unregister_chrdev(majorNumber, DEVICE_NAME);
      printk(KERN_ALERT "Failed to create the device\n");
      return PTR_ERR(charDevice);
   }
   printk(KERN_INFO "CharDev: device class created correctly\n");
   return 0;
}

// 清理模块
static void __exit chardev_exit(void){
   device_destroy(charClass, MKDEV(majorNumber, 0));
   class_unregister(charClass);
   class_destroy(charClass);
   unregister_chrdev(majorNumber, DEVICE_NAME);
   printk(KERN_INFO "CharDev: Goodbye from the CharDev LKM!\n");
}

module_init(chardev_init);
module_exit(chardev_exit);
