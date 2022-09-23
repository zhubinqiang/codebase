
obj-m := hello.o
KVERSION := $(shell uname -r)

CONFIG_MODULE_SIG=n

all :
	$(MAKE) -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	$(MAKE) -C /lib/modules/$(KVERSION)/build M=$(PWD) clean

# -C: change directory
# M=: to specify directory of external module to build

