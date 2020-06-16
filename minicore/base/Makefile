

ifdef PROG

$(PROG): $(PROG).c
ifneq ("$(wildcard $(PROG).mconf)","")
		../../mini-gcc --config  $(PROG).mconf -o $(PROG) $(PROG).c
else
		../../mini-gcc --config  $(PROG).c -o $(PROG) $(PROG).c
endif

endif


src = $(patsubst %.c,%, $(wildcard *.c))

all: README.md
		$(foreach FILE,$(src),make PROG=$(FILE);)


.PHONY: README.md

README.md: 
	cp README.in README.md
	#ls -lho --time-style=long-iso | grep -oE '\s*(\S*\s*){5}$$' >> README.md
	#echo '```'>> README.md
	perl Makeindex.pl >> README.md
	echo '```'>> README.md

