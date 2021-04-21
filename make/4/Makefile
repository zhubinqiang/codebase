
obj-m := hello.o

all :
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

# -C: change directory
# M=: to specify directory of external module to build

