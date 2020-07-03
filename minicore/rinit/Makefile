


CC=../../mini-gcc

all: init reboot halt

init: init.c
		$(CC) --config init.c -o init init.c

reboot: reboot.c
		$(CC) --shrinkelf -o reboot reboot.c

halt: halt.c
		$(CC) --shrinkelf -o halt halt.c

install:
	sudo mv /sbin/init /sbin/init.old
	sudo cp init /sbin/init
