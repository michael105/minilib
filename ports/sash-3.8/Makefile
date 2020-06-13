

all: cmds.o utils.o sash.o

%.o: %.c minilib.conf
	@echo -e "\e[36;1m ../../mini-gcc --config minilib.conf -c $< \e[37;0m"
	@../../mini-gcc --config minilib.conf -c $<



