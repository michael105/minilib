

#all: hello hello-include hello-scripted hello-unistd

all: hello hello-include hello-unistd

hello: hello.c
	 ../mini-cc --config hello.c -o hello hello.c

hello-include: hello-include.c
	../mini-cc -o hello-include hello-include.c


hello-unistd: hello-unistd.c
	../mini-cc --force --genconf hello-unistd.mconf hello-unistd.c
	../mini-cc --config hello-unistd.mconf -o hello-unistd hello-unistd.c

hello-scripted: hello-scripted.c
	../mini-cc --exec ./hello-scripted.c

