#!/bin/sh

# Update the config file of udevrd.
# Signal udevrd to reload it's configuration.


NORM=""$'\033[0;0m'""
N=""$'\033[0;0m'""

BOLD=""$'\033[1m'""
FAINT=""$'\033[2m'""
CURSIVE=""$'\033[3m'""
UNDERLINE=""$'\033[4m'""
LIGHTBG=""$'\033[5m'""
BLINK=""$'\033[6m'""
INVERTED=""$'\033[7m'""
INVERSE=""$'\033[7m'""


BLACK=""$'\033[0;30m'""
BGBLACK=""$'\033[40m'""
GRAY=""$'\033[01;30m'""
BGGRAY=""$'\033[05;40m'""

RED=""$'\033[0;31m'""
LRED=""$'\033[1;31m'""
BGRED=""$'\033[41m'""
BGLRED=""$'\033[5;41m'""

LGREEN=""$'\033[1;32m'""
GREEN=""$'\033[0;32m'""
BGGREEN=""$'\033[42m'""
BGLGREEN=""$'\033[5;42m'""

YELLOW=""$'\033[01;33m'""
BROWN=""$'\033[0;33m'""
BGBROWN=""$'\033[43m'""
BGYELLOW=""$'\033[5;43m'""

LBLUE=""$'\033[01;34m'""
BLUE=""$'\033[0;34m'""
BGBLUE=""$'\033[44m'""
BGLBLUE=""$'\033[5;44m'""

PINK=""$'\033[1;35m'""
MAGENTA=""$'\033[0;35m'""
BGMAGENTA=""$'\033[45m'""
BGPINK=""$'\033[5;45m'""
LMAGENTA=""$'\033[1;35m'""

CYAN=""$'\033[0;36m'""
BGCYAN=""$'\033[46m'""
LCYAN=""$'\033[1;36m'""
BGLCYAN=""$'\033[5;46m'""

WHITE=""$'\033[01;37m'""
BGWHITE=""$'\033[5;47m'""
LGRAY=""$'\033[0;37m'""
BGLGRAY=""$'\033[47m'""


# 256 indexed color mode
ORANGE=""$'\033[38;5;214m'""



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
		's/^x/01737777/; \
		s/\*>/07777777/; s/dir>/07040000/; \
		s/dir+/03040000/; s/dir-/040000/; s/dir/01040000/;   \
		 s/\*/0777777/; s/dev/block|char/; \
		s/file/0100000/; s/socket/0140000/; s/link/0120000/;\
		 s/block/060000/; s/char/020000/; s/fifo/010000/; s/|/|8#/g'` ))
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
    export $1="$2"
}

# ===========  "main" ==============

source ./common.conf

echo -e "\n$LGREEN Reading config in $1.$NORM\n"
cfg=`basename $1`

((source $1 >$1.tmp) 2>&1 | \
    sed -E "/^\.\/$cfg/{s/(..$cfg.*)$/$LRED\1$NORM/}" | \
    cat -n | sed '/^[[:space:]]*[[:digit:]]*[[:space:]]*#/d' | \
    sed -E "x;$,/endconfig/{x;q}; $,/error/{s/^/$LRED/p;x;s/^.*:(.*:.*)/\n\t\1/}" ) &&
    cat $1.tmp | ./udevrd-writeconf $1.bin
    #sed -E "s/^([[:digit:]]*:)/\1\t/;$,/error/i$LRED"


#(source $1 >t) 2>&1 | cat -n | sed '/^[[:space:]]*[[:digit:]]*[[:space:]]*#/d' | \
#    sed -E "s/^([[:space:]]*[[:digit:]]*[[:space:]]*..$cfg.*)/$LRED\1$NORM/" | \
#    sed -E "x;$,/error/{s/^/$LRED/p;x;s/^.*:(.*:.*)/\n\t\1/}"
    #sed -E "s/^([[:digit:]]*:)/\1\t/;$,/error/i$LRED"

echo
echo $LGREEN Ok.
echo

echo $configfile


