
MCC=../../../mini-gcc


AP=./append


all: udevrd 

install: all
	@echo Make install
	cp udevrd /sbin/
	chmod 0700 /sbin/udevrd
	cp udevrd.conf /etc/
	chmod 0600 /etc/udevrd.conf
	cp udevrd.conf.bin /etc/
	chmod 0600 /etc/udevrd.conf.bin
	cp udevrd-update.sh /usr/sbin/
	cp append /usr/bin/append
	cp udevrd-appendconf.sh /usr/sbin/

udevrd: udevrd.c udevrd.conf.h udevrd.conf.bin append log.h
	$(MCC) udevrd.c
	@echo appending config to udevrd
	cat ../udevrd.conf.bin | ./append -a udevrd
	@ls -l udevrd


udevrd.conf.bin: udevrd.conf udevrd-writeconf
	../scripts/udevrd-update.sh ../udevrd.conf

udevrd-writeconf: udevrd-writeconf.c udevrd.conf.h common.conf
	$(MCC) udevrd-writeconf.c

append: append.c
	$(MCC) append.c



