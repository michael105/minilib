/*
** setenv.c for minishell1 in ./src/cmds
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sun Nov 11 14:07:25 2012 ivan ignatiev
** Last update Sun Nov 11 18:42:50 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"arraymy.h"
#include	"stringmy.h"
#include	"minishell1.h"

int		command_setenv(char **argv, char ***env)
{
  if (argv[1] != NULL)
    {
      if (argv[2] != NULL)
	*env = my_setenv(argv[1], argv[2], *env);
      else
	*env = my_setenv(argv[1], "", *env);
    }
  else
    my_puterror("setenv: Too few arguments.\n");
  return (1);
}
