/*
** cd.c for minishell1 in ./src/cmds/
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sun Nov 11 15:48:26 2012 ivan ignatiev
** Last update Sun Nov 11 16:31:04 2012 ivan ignatiev
*/

#include	<unistd.h>
#include	"stringmy.h"
#include	"minishell1.h"

int		command_cd(char **argv, char ***env)
{
  char		*path;

  if (argv[1] != NULL)
    {
      path = argv[1];
      if (chdir(path) != 0)
	my_puterror("Error: Can't change dir\n");
    }
  else
    {
      if ((path = get_home_dir(*env)) != NULL && chdir(path) != 0)
	my_puterror("Error: Can't change dir\n");
    }
  *env = my_setenv("PWD", path, *env);
  return (1);
}
