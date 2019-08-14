pacman -Ql glibc | grep "\.h" | sed 's/glibc //' | \
		perl -n -e 'open F,"$_"; while ( <F> ){ $s=$_; if ( $s=~ /#ifndef (_+[A-Z].*H)/ ){ print "#define $1\n"; break;} } ' \
		| sort -u

