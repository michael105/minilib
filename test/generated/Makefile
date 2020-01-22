
bin = $(patsubst %.c,%,$(wildcard *.c))

all: $(bin)

clean:
	rm $(bin)

%: %.c
	echo $@ $<
	../../mini-gcc --compile $<


test: $(bin)

#	$(foreach f,$(bin), $(shell ./$(f) && if [ "$?" = "42" ]; then echo $(f) Ok; else echo $(f) error; fi ); )

