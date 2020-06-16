/*
** io.c for minishell2 in /home/ignati_i//projects/minishell2/src
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Nov 28 11:04:24 2012 ivan ignatiev
** Last update Sun Dec  2 15:14:25 2012 ivan ignatiev
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"minishell1.h"
#include	"stringmy.h"
#include	"arraymy.h"

int		exec_cmds_by_order(char *cmd, char ***env)
{
  char		**command_list;
  int		i;

  if ((command_list = my_split_string(cmd, ";", 1)) != NULL)
    {
      i = 0;
      while (command_list[i] != NULL)
	{
	  if (!exec_command_pipe(command_list[i], env))
	    {
	      my_puterror("mysh: I/O error.\n");
	      return (my_free_array(command_list) && 0);
	    }
	  i = i + 1;
	}
      return (my_free_array(command_list) && 1);
    }
  return (0);
}
