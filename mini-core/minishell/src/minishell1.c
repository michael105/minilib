/*
** minishell1.c for minishell1 in ./src/
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Fri Nov  9 20:03:49 2012 ivan ignatiev
** Last update Sun Dec  2 15:12:15 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<signal.h>
#include	"arraymy.h"
#include	"stringmy.h"
#include	"minishell1.h"

int		g_busy;

int		command_line(char ***env)
{
  char	buf[1024];
  int	size;

  my_putstr("$>");
  while ((size = read(0, buf, 1024)) > 0)
    {
      if (buf[size - 1] == '\n')
	{
	  g_busy = 0;
	  buf[size] = '\0';
	  exec_cmds_by_order(buf, env);
	  my_putstr("$>");
	}
      else
	{
	  g_busy = 1;
	  while ((size = read(0, buf, 1024)) > 0);
	  my_puterror("Error: Command can containt only 1024 characters\n");
	}
    }
  if (size == 0)
    my_free_array(*env);
  return (size);
}

void		signal_handler_ctrl_c(int signal)
{
  if (signal && g_busy)
    exit(EXIT_FAILURE);
}

int		main(int argc, char **argv, char **env)
{
  char		**my_env;
  int		options;

  g_busy = 0;
  if ((options = manage_options(argc, argv)) >= 0)
    {
      my_env = my_array_from_array(env);
      signal(SIGINT, signal_handler_ctrl_c);
      while (command_line(&my_env) > 0);
    }
  return (0);
}
