#!/bin/sh





if [ -n "$1" ]; then
		cfg="$1"
else
		cfg="/etc/udevrd.conf.bin"
fi
	
if [ -n "$2" ]; then
		udevrd="$2"
else
		udevrd="/sbin/udevrd"
fi


echo Appending $cfg to $udevrd

cat $cfg | append -r $udevrd


