#!/bin/sh

export X=xxz


echo sourced T12


async T12 "sleep 3; echo T12 ok"

cat /etc/rinit/boot/wait.count

#echo 1 > /etc/rinit/boot/wait.fifo &

