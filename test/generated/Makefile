
bin = $(patsubst %.c,%,$(wildcard *.c))

all: $(bin)

clean:
	rm -f $(bin)

%: %.c
	echo $@ $<
	( ../../minimake --verbose --compile $< 2>&1 || mv $< ./fail/ ) | tee $@.log

p:
	perl -e 'print "Ok\n"'

sizes: all
	./writesizes.pl | sort -t : -k 2 -g > sizes.txt

cs: createsources

createsources:
	sed -i '/DEF/d' functions.txt
	./genprogs.pl

test: all
	find . -executable | sed -n '2,$$p' | sed -e '/select/d' -e '/\.pl$$/d' > executable.txt
	perl -ne 'chomp; $$s=$$_; print "$$s\n"; if ( $$s=~/fget/ ){  system("echo | $$s"); } else { system("$$s"); } print "",( $$?>>8 ),"\n"' executable.txt






#	$(foreach f,$(bin), $(shell ./$(f) && if [ "$?" = "42" ]; then echo $(f) Ok; else echo $(f) error; fi ); )

