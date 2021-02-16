
MCC=../../../mini-gcc

AP=./append
PATH := $(PWD):$(PATH)

all: udevrd 

install: all
	@echo Make install
	cp udevrd /sbin/
	chmod 0700 /sbin/udevrd
	cp udevrd-writeconf /usr/sbin/
	cp append /usr/bin/
	cp gid /usr/bin/


udevrd: udevrd.c udevrd.conf.h ../udevrd.conf.bin append log.h gid
	$(MCC) udevrd.c
	@echo appending config to udevrd
	cat ../udevrd.conf.bin | ./append -a udevrd
	@ls -l udevrd


../udevrd.conf.bin: ../udevrd.conf udevrd-writeconf
	../scripts/udevrd-update.sh ../udevrd.conf

udevrd-writeconf: udevrd-writeconf.c udevrd.conf.h common.conf
	$(MCC) udevrd-writeconf.c

append: append.c
	$(MCC) append.c

gid: gid.c
	$(MCC) gid.c



