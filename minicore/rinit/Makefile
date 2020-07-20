


CC=../../mini-gcc

all: init reboot halt

init: init.c
		$(CC) --config init.c -o init init.c

reboot: reboot.c
		$(CC) --shrinkelf -o reboot reboot.c

halt: halt.c
		$(CC) --shrinkelf -o halt halt.c

install: init
	sudo mv /sbin/init /sbin/init.bak
	sudo cp init /sbin/init

install-tools: halt reboot
	@echo assuming the group wheel is existent
	@echo and wheel is the group intended for users allowed to reboot/shutdown
	sudo "cp halt /bin/halt && chown root:wheel /bin/halt && chmod ug+s /bin/halt"
	sudo "cp reboot /bin/reboot && chown root:wheel /bin/reboot && chmod ug+s /bin/reboot"

