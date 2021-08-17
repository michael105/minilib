

#all: hello hello-include hello-scripted hello-unistd

all: hello hello-include hello-unistd

hello: hello.c
	 ../mlcc --config hello.c -o hello hello.c

hello-include: hello-include.c
	../mlcc -o hello-include hello-include.c


hello-unistd: hello-unistd.c
	../mlcc --force --genconf hello-unistd.mconf hello-unistd.c
	../mlcc --config hello-unistd.mconf -o hello-unistd hello-unistd.c

hello-scripted: hello-scripted.c
	../mlcc --exec ./hello-scripted.c

