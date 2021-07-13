#!/bin/sh
# system one time tasks

PATH=/sbin:/usr/sbin:/bin:/usr/bin:/bb

#source lib.sh


touch /etc/runit/reboot
chmod 0 /etc/runit/reboot
touch /etc/runit/stopit
chmod 0 /etc/runit/stopit



#RUNLEVEL=S /sbin/rc sysinit
#RUNLEVEL=S /sbin/rc boot
# runsvdir /etc/rinit/boot   no. wrong ;

# wait for 0 async processes
# counts up for each asyncron started process
echo 0 > /etc/rinit/boot/wait.count
echo 0 > /etc/rinit/boot/finished.count

for i in ./test/S*
do
		echo Start `basename $i`
		eval source $i
done

echo 
echo --- Boot started

exit 0


i=0
while [ $i -lt `cat /etc/rinit/boot/wait.count` ]  && [ `cat /etc/rinit/boot/wait.count` -gt `cat /etc/rinit/boot/finished.count` ]
do
		i=$(( $i + 1 ))
		cat /etc/rinit/boot/wait.fifo
		
done



