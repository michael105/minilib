MCC=../../mini-cc


src = $(patsubst %.c,%, $(wildcard *.c))

all: $(src) 

%: %.c
	$(eval OPT=--config $@.c)
	$(if $(wildcard $@.mconf),$(eval OPT=--config $@.mconf),)
	$(if $(wildcard $@.conf),$(eval OPT=--config $@.conf),)
	@echo -e "\e[36m" $(MCC) $(OPT) -o $@ $@.c "\e[37m"
	@$(MCC) $(OPT) -o $@ $@.c
	@touch README.in 



#.PHONY: README.md

README.md: 
	cp README.in README.md
	#ls -lho --time-style=long-iso | grep -oE '\s*(\S*\s*){5}$$' >> README.md
	#echo '```'>> README.md
	perl Makeindex.pl >> README.md
	echo '```'>> README.md

