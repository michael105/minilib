/*
** exec.c for minishell1 in ./src
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Nov 10 20:07:23 2012 ivan ignatiev
** Last update Sun Dec  2 15:14:53 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	"stringmy.h"
#include	"arraymy.h"
#include	"minishell1.h"

int		control_default_cmd(char **argv, char ***env)
{
  if (my_strcmp(argv[0], "exit") == 0)
    return (command_exit(argv, *env));
  else  if (my_strcmp(argv[0], "setenv") == 0)
    return (command_setenv(argv, env));
  else  if (my_strcmp(argv[0], "unsetenv") == 0)
    return (command_unsetenv(argv, env));
  else  if (my_strcmp(argv[0], "env") == 0)
    return (command_env(argv, env));
  else  if (my_strcmp(argv[0], "cd") == 0)
    return (command_cd(argv, env));
  return (0);
}

int		child(char **argv, char **env, int ifd, int ofd)
{
  dup2(ifd, 0);
  dup2(ofd, 1);
  if (execve(get_bin_path(argv[0], env), argv, env) < 0)
    {
      my_puterror(argv[0]);
      my_puterror(": command not found\n");
      return (0);
    }
  close(ifd);
  close(ofd);
  return (1);
}

int		execute_command(char *cmd, char ***env, int ifd, int ofd)
{
  char		**argv;
  pid_t		pid;

  if ((argv = my_parse_args(cmd, *env)) != NULL)
    if (!control_default_cmd(argv, env))
      {
	if ((pid = fork()) >= 0)
	  {
	    if (pid == 0)
	      {
		if (!child(argv, *env, ifd, ofd))
		  {
		    my_free_array(argv);
		    exit(EXIT_FAILURE);
		  }
		exit(EXIT_SUCCESS);
	      }
	    else
	      {
		my_free_array(argv);
		return (pid);
	      }
	  }
      }
  return (-1);
}
