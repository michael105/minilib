/*
** exit.c for minishell1 in ./src/cmds/
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sun Nov 11 10:50:10 2012 ivan ignatiev
** Last update Sun Nov 11 18:42:33 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"arraymy.h"
#include	"stringmy.h"
#include	"minishell1.h"

int		command_exit(char **argv, char **env)
{
  int		status;

  status = 0;
  if (argv[1] != NULL)
    status = my_getnbr(argv[1]);
  my_free_array(argv);
  my_free_array(env);
  exit(status);
  return (1);
}
