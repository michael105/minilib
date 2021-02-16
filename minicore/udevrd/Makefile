



all: udevrd.conf.bin src/udevrd

install: all
	cd src && make install
	cd scripts && make install
	cp udevrd.conf /etc/
	chmod 0600 /etc/udevrd.conf
	cp udevrd.conf.bin /etc/
	chmod 0600 /etc/udevrd.conf.bin

udevrd.conf.bin: udevrd.conf
	echo $(PATH)
