

#all: hello hello-include hello-scripted hello-unistd

all: hello hello-include hello-unistd

hello: hello.c
	 ../minicc --config hello.c -o hello hello.c

hello-include: hello-include.c
	../minicc -o hello-include hello-include.c


hello-unistd: hello-unistd.c
	../minicc --force --genconf hello-unistd.mconf hello-unistd.c
	../minicc --config hello-unistd.mconf -o hello-unistd hello-unistd.c

hello-scripted: hello-scripted.c
	../minicc --exec ./hello-scripted.c

