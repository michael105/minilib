
PROGS := hello hello-tiny
OBJS := hello.conf

MINIMAKE="../minimake"


all: $(PROGS)

hello: hello.c
	 sh compile_hello.sh

hello-tiny: hello.c hello-tiny.conf
	$(MINIMAKE) hello-tiny.conf



clean: 
	rm -f $(PROGS) 
	rm -f $(OBJS)
