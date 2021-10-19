
PROGS := hello hello-tiny hello-singlefile
OBJS := hello.conf

MINIMAKE="../minimake"


all: $(PROGS)

hello: hello.c
	 sh compile_hello.sh

hello-tiny: hello.c hello-tiny.conf
	$(MINIMAKE) hello-tiny.conf

hello-singlefile: hello-singlefile.c
	$(MINIMAKE) hello-singlefile.c

clean: 
	rm -f $(PROGS) 
	rm -f $(OBJS)
