
MCC=../minilib/mini-gcc

AP=./append
PATH := $(PWD):$(PATH)

all: gid append 

install: all
	@echo Make install
	cp append /usr/bin/
	cp gid /usr/bin/



append: append.c
	$(MCC) append.c

gid: gid.c
	$(MCC) gid.c



