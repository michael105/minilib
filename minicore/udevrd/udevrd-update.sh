#!/bin/sh

# Update the config file of udevrd.
# Signal udevrd to reload it's configuration.


function endconfig(){
		#printf '%-31s\n' "$logprefix" | sed -E 's/ /\x0/g;s/\x0([[:alpha:]])/ \1/g'
		echo $loglevel
		echo $logfacility
		echo $logcolor
		echo $logprefix
		echo $devpath
}


function conf_devpath(){
		devpath=$1
}


function conf_loglevel(){
		loglevel=$1
}

function conf_logfacility(){
		logfacility=$1
}

function conf_logprefix(){
		logprefix=$1
}

function conf_logcolor(){
		logcolor=$1
}

function conf(){
		param=$1
		shift
		"conf_$param" $*
}

function uid(){
    if [ "$1" == "x" ] || [ -z $1 ]; then
	id -u nobody
    else
	echo "$1" | sed -E 's/(.*):.*/id -u \1/e'
    fi
}

function guid(){
		if [ "$1" == "x" ] || [ -z $1 ]; then
				/bin/gid nobody
		else
				echo $1 | sed -E 's/(.*):.*/id -g \1/e'
		fi
}



function gid(){
		if [ "$1" == "x" ] || [ -z $1 ]; then
				/bin/gid nobody
		else
				echo $1 | sed -E 's/.*:(.*)/gid \1/e'
		fi
}

function stripx(){
		if [ "$1" != "x" ];then
				echo "$1"
		else
				echo
		fi
}

function tt(){
    echo $(( 8#`echo "$1" | sed \
		's/^x/0730000/; \
		s/\*>/07777777/; s/dir>/07040000/; \
		s/dir+/03040000/; s/dir-/040000/; s/dir/01040000/;   \
		 s/\*/0777777/; s/dev/block|char/; \
		s/file/0100000/; s/socket/0140000/; s/link/0120000/;\
		 s/block/060000/; s/char/020000/; s/fifo/010000/; s/|/|8#/g'` ))
    # distinguish between block and char device
}
function match(){
		echo
		tt "$1"
		uid $3
		gid $3
		# access
		echo $(( 8#$4 ))
		# exec as uid/gid
		uid $6
		guid $6
		uid $8
		guid $8
		
		# pattern
		echo "$2"
		#log msg
		echo "$7"
		# link
		stripx "$5"
		# execute
		echo "$6" | sed 's/.*://'
		# execute on removal
		echo $8 | sed 's/.*://'

}

function endfile(){
    echo 255
}  

function define(){
    param=$1
    shift
    export $param="$*"
}

# ===========  "main" ==============

source ./common.conf

echo -e $LICENSENOTE
echo

if [ -z $1 ]; then
    echo usage: $0 configfile
    echo
    exit
fi

echo -e "\n$LGREEN Reading config in $1.$NORM\n"
cfg=`basename $1`
echo $cfg

((source $1 >$1.tmp) 2>&1 | \
    #sed -nE "/^\.\/$cfg/{s/^(\.\/$cfg.*)$/$LRED\1$NORM/;x;G;s/\n/ /;h;d};x;p"';${x;p}' | \
    sed -nE "/^\.\/$cfg/{s/^(\.\/$cfg.*)$/$LRED\1$NORM/;x;G;s/\n/ /;h;x;p;x;p;q};x;p"';${x;p}' | \
    cat -n | sed '/^[[:space:]]*[[:digit:]]*[[:space:]]*#/d' | \
    sed -E "/endfile/{d;q}; $,/error/{s/^.*:(.*:.*)/\n\t$LRED\1\n/}" ) &&
    cat $1.tmp | ./udevrd-writeconf $1.bin && \
    (echo -e "\n$LGREEN Ok\n";killall -SIGUSR1 udevrd 2>/dev/null;true) ||
    echo -e "\n$LRED Error\n"
    #sed -E "s/^([[:digit:]]*:)/\1\t/;$,/error/i$LRED"


#((source $1 >$1.tmp) 2>&1 | \
#    sed -E "/^\.\/$cfg/{s/(..$cfg.*)$/$LRED\1$NORM/}" | \
#    cat -n | sed '/^[[:space:]]*[[:digit:]]*[[:space:]]*#/d' | \
#    sed -E "x;$,/endconfig/{x;q}; $,/error/{s/^/$LRED/p;x;s/^.*:(.*:.*)/\n\t\1/}" ) &&
#    cat $1.tmp | ./udevrd-writeconf $1.bin && \
#    echo -e "\n$LGREEN Ok\n" ||
#    echo -e "\n$LRED Error\n"
# 
#(source $1 >t) 2>&1 | cat -n | sed '/^[[:space:]]*[[:digit:]]*[[:space:]]*#/d' | \
#    sed -E "s/^([[:space:]]*[[:digit:]]*[[:space:]]*..$cfg.*)/$LRED\1$NORM/" | \
#    sed -E "x;$,/error/{s/^/$LRED/p;x;s/^.*:(.*:.*)/\n\t\1/}"
    #sed -E "s/^([[:digit:]]*:)/\1\t/;$,/error/i$LRED"




