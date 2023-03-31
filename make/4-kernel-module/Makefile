## to avoid this issue
# "module verification failed: signature and/or required key missing - tainting kernel"
CONFIG_MODULE_SIG=n
CONFIG_MODULE_SIG_ALL=n

obj-m := hello.o

all :
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

# -C: change directory
# M=: to specify directory of external module to build

