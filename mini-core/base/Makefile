

ifdef PROG

$(PROG): $(PROG).c
ifneq ("$(wildcard $(PROG).mconf)","")
		mini-gcc --config  $(PROG).mconf -o $(PROG) $(PROG).c
else
		mini-gcc --config  $(PROG).c -o $(PROG) $(PROG).c
endif

endif


src = $(patsubst %.c,%, $(wildcard *.c))

all:
		$(foreach FILE,$(src),make PROG=$(FILE);)
