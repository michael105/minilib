/*
** unsetenv.c for minishell1 in ./src/cmds
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sun Nov 11 16:33:19 2012 ivan ignatiev
** Last update Sun Nov 11 18:43:53 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"stringmy.h"
#include	"arraymy.h"
#include	"minishell1.h"

int		command_unsetenv(char **argv, char ***env)
{
  if (argv[1] != NULL)
    {
      *env = my_unsetenv(argv[1], *env);
    }
  else
    my_puterror("unsetenv: Too few arguments.\n");
  return (1);
}
