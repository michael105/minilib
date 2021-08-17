#!/bin/sh

# THESE damned makefile syntax sometimes drives me crazy.


while [ "$1" != "" ]
do
		echo $1
		( echo -n "$1" | sed -e "s/.*\///" -e "s/\./_/g" &&  echo "='" &&\
				cat $1 && echo "'" ) \
		 		| scripts/template.pl -insert mlcc content-ldscript



		shift
done


