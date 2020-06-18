// including all sources gives more possibilities for the compiler to optimize..
#include "./src/cmds/cd.c"
#include "./src/cmds/env.c"
#include "./src/cmds/exit.c"
#include "./src/cmds/unsetenv.c"
#include "./src/cmds/setenv.c"
#include "./src/io.c"
#include "./src/env.c"
#include "./src/io_redirect.c"
#include "./src/args.c"
#include "./src/exec.c"
#include "./src/io_pipe.c"
#include "./src/path.c"
#include "./src/options.c"
#include "./src/minishell1.c"
#include "./src/arraymy/my_remove_from_array.c"
#include "./src/arraymy/my_array_length.c"
#include "./src/arraymy/my_array_from_array.c"
#include "./src/arraymy/my_free_array.c"
#include "./src/arraymy/my_split_string.c"
#include "./src/arraymy/my_print_array.c"
#include "./src/arraymy/my_add_to_array.c"
#include "./src/includes.c"
#include "./src/stringmy/my_getnbr.c"
#include "./src/stringmy/merge_strings.c"
#include "./src/stringmy/my_strncat.c"
#include "./src/stringmy/my_strncmp.c"
#include "./src/stringmy/my_strncpy.c"
#include "./src/stringmy/my_putchar.c"
#include "./src/stringmy/my_strcat.c"
#include "./src/stringmy/my_strcmp.c"
#include "./src/stringmy/my_strcpy.c"
#include "./src/stringmy/my_strlen.c"
#include "./src/stringmy/my_puterror.c"
#include "./src/stringmy/my_putstr.c"
