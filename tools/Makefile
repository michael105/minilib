PROGS=shrinkelf removeccomments stripblanks

all: $(PROGS)

%: %.c
	../mlcc $<

shrinkelf: shrinkelf.c
	../mlcc --config shrinkelf.mconf -o shrinkelf shrinkelf.c

clean:
	rm $(PROGS)
