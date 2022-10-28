obj-m = dev_nr.o

KVERSION = $(shell uname -r)
all:
	 make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	 make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
