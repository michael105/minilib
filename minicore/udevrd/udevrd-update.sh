#!/bin/bash

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
				echo $1 | sed -E 's/(.*):.*/id -u \1/e'
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


function match(){
		echo
		uid $2
		gid $2
		# access
		echo $(( 8#$3 ))
		# exec as uid/gid
		uid $5
		guid $5
		uid $7
		guid $7
		
		# pattern
		echo "$1"
		#log msg
		echo "$6"
		# link
		echo "$4"
		# execute
		echo $5 | sed 's/.*://'
		# execute on removal
		echo $7 | sed 's/.*://'

}


source $1

# end with ack
echo 255

