


CC=../../minicc

all: init reboot halt rinit.boot rinit.run





init: src/init.c
		$(CC) --config src/init.c -o init src/init.c

reboot: src/reboot.c
		$(CC) --shrinkelf -o reboot src/reboot.c

halt: src/halt.c
		$(CC) --shrinkelf -o halt src/halt.c

install: init
	sudo mv /sbin/init /sbin/init.bak
	sudo cp init /sbin/init

install-tools: halt reboot
	@echo assuming the group wheel is existent
	@echo and wheel is the group intended for users allowed to reboot/shutdown
	sudo "cp halt /bin/halt && chown root:wheel /bin/halt && chmod ug+s /bin/halt"
	sudo "cp reboot /bin/reboot && chown root:wheel /bin/reboot && chmod ug+s /bin/reboot"


%: src/%.c src/common.c src/config.h src/minilib.conf
	$(eval OPT=--config src/minilib.conf) 
	@echo -e "\e[36m" $(CC) $(OPT) -o $@ $@.c "\e[37m"
	@$(CC) $(OPT) -o $@ $<


