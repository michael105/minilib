
MCC=../../mini-gcc


AP=./append


all: udevrd 


udevrd: udevrd.c udevrd.conf.h udevrd.conf.bin append 
	$(MCC) udevrd.c
	@echo appending config to udevrd
	cat udevrd.conf.bin | ./append -a udevrd
	@ls -l udevrd


udevrd.conf.bin: udevrd.conf udevrd-writeconf
	./udevrd-update.sh ./udevrd.conf

udevrd-writeconf: udevrd-writeconf.c udevrd.conf.h common.conf
	$(MCC) udevrd-writeconf.c

append: append.c
	$(MCC) append.c



