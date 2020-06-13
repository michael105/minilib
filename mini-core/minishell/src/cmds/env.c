/*
** env.c for minishell1 in ./src/cmds
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sun Nov 11 17:13:21 2012 ivan ignatiev
** Last update Sun Nov 11 17:56:42 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"stringmy.h"
#include	"arraymy.h"
#include	"minishell1.h"

int		command_env(char **argv, char ***env)
{
  if (argv[1] != NULL)
    {
      my_puterror("Sorry, but env didn't suppose any arguments.\n");
    }
  else
    {
      my_print_array(*env);
    }
  return (1);
}
