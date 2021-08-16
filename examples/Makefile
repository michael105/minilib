

#all: hello hello-include hello-scripted hello-unistd

all: hello hello-include hello-unistd

hello: hello.c
	 ../mini-gcc --config hello.c -o hello hello.c

hello-include: hello-include.c
	../mini-gcc -o hello-include hello-include.c


hello-unistd: hello-unistd.c
	../mini-gcc --force --genconf hello-unistd.mconf hello-unistd.c
	../mini-gcc --config hello-unistd.mconf -o hello-unistd hello-unistd.c

hello-scripted: hello-scripted.c
	../mini-gcc --exec ./hello-scripted.c

