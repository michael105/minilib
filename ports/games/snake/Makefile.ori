CC ?= gcc
NAME = snake

WARN = -ansi -Wall -Wextra -Werror
CFLAGS =
LFLAGS =

SRC = snake.c

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LFLAGS) $(WARN) -o $(NAME)

debug: $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LFLAGS) $(WARN) -o $(NAME) -g -O0

clean: $(NAME)
	rm $(NAME)
