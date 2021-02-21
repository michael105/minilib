
PATH := $(PWD)/scripts:$(PWD)/src:$(PATH)

all: udevrd.conf.bin 

install: all
	cd src && make install
	cd scripts && make install
	cp udevrd.conf /etc/
	chmod 0600 /etc/udevrd.conf
	cp udevrd.conf.bin /etc/
	chmod 0600 /etc/udevrd.conf.bin

udevrd.conf.bin: udevrd.conf src/udevrd src/udevrd-writeconf
	./scripts/udevrd-update.sh $(PWD)/udevrd.conf

src/%:
	cd src && make


