

#all: hello hello-include hello-scripted hello-unistd

all: hello hello-include hello-unistd

hello: hello.c
	 ../minimake --config hello.c -o hello hello.c

hello-include: hello-include.c
	../minimake -o hello-include hello-include.c


hello-unistd: hello-unistd.c
	../minimake --force --genconf hello-unistd.mconf hello-unistd.c
	../minimake --config hello-unistd.mconf -o hello-unistd hello-unistd.c

hello-scripted: hello-scripted.c
	../minimake --exec ./hello-scripted.c

