.POSIX:
.SUFFIXES:
NAME    = sxinit
CC      = cc
CFLAGS  = -std=c99 -pedantic -Wall -Werror -D_POSIX_C_SOURCE=200809L
LDFLAGS =
SRC     = $(NAME).c
OBJ     = ${SRC:.c=.o}


all: $(NAME)

$(NAME): $(NAME).o
	$(CC) $(LDFLAGS) -o $@ $^

.SUFFIXES: .c .o
$(OBJ):
.c.o:
	$(CC) $(CFLAGS) -c $<

install: all
	mkdir -p $(PREFIX)/bin
	cp -f $(NAME) $(PREFIX)/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/$(NAME)

.PHONY: clean
clean:
	rm -f -- $(NAME) $(OBJ)
