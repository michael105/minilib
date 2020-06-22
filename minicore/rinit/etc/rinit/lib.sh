# functions for rinit


# geht so lala
function async (){
		name=$1
		shift
		flock /etc/rinit/boot/wait.count echo $(( `cat /etc/rinit/boot/wait.count` + 1 )) > /etc/rinit/boot/wait.count
		( eval "$*" \
				&& ( flock /etc/rinit/boot/finished.count echo $(( `cat /etc/rinit/boot/finished.count` + 1 )) > /etc/rinit/boot/finished.count
							flock /etc/rinit/boot/wait.count echo =*= $name > /etc/rinit/boot/wait.fifo ) \
				|| (  flock /etc/rinit/boot/finished.count echo $(( `cat /etc/rinit/boot/finished.count` + 1 )) > /etc/rinit/boot/finished.count
							flock /etc/rinit/boot/wait.count echo =X= $name > /etc/rinit/boot/wait.fifo )
			) &
		
}



