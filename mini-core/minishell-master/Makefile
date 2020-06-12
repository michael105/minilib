##
## Makefile for minishell1 in /home/ignati_i//test_c/minishell1
## 
## Made by ivan ignatiev
## Login   <ignati_i@epitech.net>
## 
## Started on  Sat Nov  3 01:52:16 2012 ivan ignatiev
## Last update Sun Dec  2 14:32:33 2012 ivan ignatiev
##

SRCS	=	src/minishell1.c \
		src/env.c \
		src/path.c \
		src/exec.c \
		src/args.c \
		src/options.c \
		src/io.c \
		src/io_pipe.c \
		src/io_redirect.c \
		src/cmds/cd.c \
		src/cmds/setenv.c \
		src/cmds/unsetenv.c \
		src/cmds/env.c \
		src/cmds/exit.c \
		src/arraymy/my_add_to_array.c \
		src/arraymy/my_array_from_array.c \
		src/arraymy/my_remove_from_array.c \
		src/arraymy/my_split_string.c \
		src/arraymy/my_print_array.c \
		src/arraymy/my_free_array.c \
		src/arraymy/my_array_length.c \
		src/stringmy/my_putchar.c \
		src/stringmy/my_putstr.c \
		src/stringmy/my_puterror.c \
		src/stringmy/my_strcat.c \
		src/stringmy/my_strlen.c \
		src/stringmy/my_strcpy.c \
		src/stringmy/my_strncpy.c \
		src/stringmy/my_strncat.c \
		src/stringmy/my_strncmp.c \
		src/stringmy/my_strcmp.c \
		src/stringmy/merge_strings.c \
		src/stringmy/my_getnbr.c

CFLAGS	+=	-Wall -Werror
CFLAGS	+=	-pedantic -Wextra
CFLAGS	+=	-I./include

NAME	=	mysh

OBJS	=	$(SRCS:.c=.o)

CC	=	../../mini-gcc

RM	=	rm -f


msh:
	../../mini-gcc -o msh src/*.c src/*/*.c -I./include -Dmini_INCLUDESRC -Dmini_buf=64000
	../../tools/shrinkelf msh


all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) -static

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean
