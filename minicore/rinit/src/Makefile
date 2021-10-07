MCC=../../../minicc
APPEND="-DPWD=${PWD}"


src = rinit.run rinit.boot reboot halt init rd.note rd.wait
OPT=--config minilib.conf

all: $(src) 

%: %.c config.h
	$(eval OPT=--config $@.c)
	$(if $(wildcard $@.mconf),$(eval OPT=--config $@.mconf),)
	$(if $(wildcard $@.conf),$(eval OPT=--config $@.conf),)
	@echo -e "\e[36m" $(MCC) $(OPT) -o $@ $@.c"\e[37m"
	@$(MCC) $(OPT) -o $@ $@.c ${APPEND}

rinit.run: rinit.run.c common.c config.h
	$(eval OPT=--config $@.c)
	$(MCC) $(OPT) -o rinit.run rinit.run.c

rinit.boot: rinit.boot.c common.c config.h
	$(eval OPT=--config $@.c)
	$(MCC) $(OPT) -o rinit.boot rinit.boot.c


reboot: reboot.c
		$(MCC) --shrinkelf -o reboot reboot.c

halt: halt.c
		$(MCC) --shrinkelf -o halt halt.c

install: init
	sudo mv /sbin/init /sbin/init.bak2
	sudo cp init /sbin/init

