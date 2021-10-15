#!/bin/sh

# Generate the configuration for hello.c,
# and compile hello

# assume being in the minimake source hierarchy
if [ -z "$MINIMAKE" ]; then
	MINIMAKE="../minimake"
fi



# generate the configuration
$MINIMAKE --genconf hello.conf hello.c 

# make the configuration
$MINIMAKE hello.conf

