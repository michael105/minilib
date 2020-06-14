FLAGS=

all: cmds.o utils.o sash.c minilib.conf
	../../mini-gcc --config minilib.conf -o sash sash.c *.o -DINCLUDESRC $(FLAGS)

%.o: %.c minilib.conf
	@echo -e "\e[36;1m ../../mini-gcc --config minilib.conf -c $< $(FLAGS)\e[37;0m"
	@../../mini-gcc --config minilib.conf -c $< $(FLAGS)



