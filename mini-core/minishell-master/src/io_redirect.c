/*
** io_redirect.c for minishell2 in /home/ignati_i//projects/minishell2
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sun Dec  2 14:29:44 2012 ivan ignatiev
** Last update Sun Dec  2 17:48:34 2012 ivan ignatiev
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"minishell1.h"
#include	"stringmy.h"
#include	"arraymy.h"

void		read_from_stdin(int ofd)
{
  char		buf[1024];
  int		sz;

  my_putstr("? ");
  while ((sz = read(0, buf, 1024)) > 0)
    {
      if (write(ofd, buf, sz) < sz)
	return ;
      my_putstr("? ");
    }
}

int		open_input(char *file, int append, int ifd, char **env)
{
  char		**filename;
  int		fd;
  int		pipefd[2];

  if ((filename = my_parse_args(file, env)) != NULL)
    {
      if (append)
	{
	  pipe(pipefd);
	  read_from_stdin(pipefd[1]);
	  close(pipefd[1]);
	  ifd = pipefd[0];
	}
      else if ((fd = open(filename[0], O_RDONLY)) >= 0)
	ifd = fd;
      my_free_array(filename);
    }
  return (ifd);
}

int		open_output(char *file, int append, int ofd, char **env)
{
  char		**filename;
  int		fd;
  int		flgs;

  if ((filename = my_parse_args(file, env)) != NULL)
    {
      flgs = O_WRONLY | O_CREAT;
      if (append)
	flgs = flgs | O_APPEND;
      else
	flgs = flgs | O_TRUNC;
      if ((fd = open(filename[0], flgs,
		     S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH)) >= 0)
	ofd = fd;
      my_free_array(filename);
    }
  return (ofd);
}

void		proccess_redirect(char *cmd, char **rdt, int fd[2], char **env)
{
  int		i;
  int		j;

  i = 0;
  j = 1;
  while (cmd[i] != '\0')
    {
      if (cmd[i] == '<' && cmd[i + 1] == '<')
	{
	  fd[0] = open_input(rdt[j++], 1, fd[0], env);
	  i = i + 1;
	}
      else if (cmd[i] == '>' && cmd[i + 1] == '>')
	{
	  fd[1] = open_output(rdt[j++], 1, fd[1], env);
	  i = i + 1;
	}
      else if (cmd[i] == '<')
	fd[0] = open_input(rdt[j++], 0, fd[0], env);
      else if (cmd[i] == '>')
	fd[1] = open_output(rdt[j++], 0, fd[1], env);
      i = i + 1;
    }
}

int		exec_command_ior(char *cmd, char ***env, int ifd, int ofd)
{
  char		**rdt;
  int		pid;
  int		new_fd[2];

  new_fd[0] = ifd;
  new_fd[1] = ofd;
  if ((rdt = my_split_string(cmd, "><", 1)) != NULL)
    {
      proccess_redirect(cmd, rdt, new_fd, *env);
      pid = execute_command(rdt[0], env, new_fd[0], new_fd[1]);
      if (new_fd[0] != ifd)
	close(new_fd[0]);
      if (new_fd[1] != ofd)
	close(new_fd[1]);
      my_free_array(rdt);
      return (pid);
    }
  return (-1);
}
