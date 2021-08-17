PROGS=shrinkelf removeccomments stripblanks

all: $(PROGS)

%: %.c
	../mlcc -mlc $<

shrinkelf: shrinkelf.c
	../mlcc --config shrinkelf.mconf -o shrinkelf shrinkelf.c

clean:
	rm $(PROGS)
