/*
** args.c for minishell1 in ./src
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Nov 10 20:01:37 2012 ivan ignatiev
** Last update Sun Nov 11 16:08:30 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"arraymy.h"
#include	"stringmy.h"
#include	"minishell1.h"

int		replace_variable(char **str, char **env)
{
  char		*value;
  int		value_len;
  int		name_len;
  int		i;

  name_len = my_strlen((*str) + 1) + 1;
  if ((i = my_getenv((*str) + 1, env)) >= 0)
    {
      value_len = my_strlen(env[i] + name_len);
      value = (char*)malloc(sizeof(char) * (value_len + 1));
      if (value != NULL)
	{
	  my_strcpy(value, env[i] + name_len);
	  free(*str);
	  *str = value;
	}
    }
  return (0);
}

char		*get_variable_value(char *result, int *i, char *str, char **env)
{
  int		start;
  int		var_n;
  char		*search;
  char		name_len;

  start = *i + 1;
  *i = *i + 1;
  while ((str[*i] >= 'A' && str[*i] <= 'Z') || (str[*i] == '_') ||
	 (str[*i] >= 'a' && str[*i] <= 'z') ||
	 (str[*i] >= '0' && str[*i] <= '9'))
    *i = *i + 1;
  name_len = (*i) - start;
  search = (char*)malloc(sizeof(char) * (name_len + 1));
  if (search != NULL)
    {
      my_strncpy(search, str + start, name_len);
      if ((var_n = my_getenv(search, env)) > 0)
	{
	  free(search);
	  return (merge_strings(result, env[var_n] + name_len + 1,
				my_strlen(env[var_n] + name_len + 1)));
	}
      free(search);
    }
  return (result);
}

int		replace_quotes(char **str, char **env, int doubled)
{
  int		i;
  int		last;
  char		*result;

  i = 1;
  last = 1;
  result = NULL;
  while ((*str)[i] != '\0'
	 && (*str)[i] != '\''
	 && (*str)[i] != '"')
    {
      if ((*str)[i] == '$' && doubled)
	{
	  result = merge_strings(result, (*str) + last, i - last);
	  result = get_variable_value(result, &i, *str, env);
	  last = i;
	}
      i = i + 1;
    }
  result = merge_strings(result, (*str) + last, my_strlen(*str) - 1 - last);
  free(*str);
  *str = result;
  return (1);
}

void		replace_home_symbol(char **str, char **env)
{
  char		*result;
  char		*home_path;

  if ((home_path = get_home_dir(env)) != NULL)
    {
      result = NULL;
      result = merge_strings(result, home_path, my_strlen(home_path));
      result = merge_strings(result, (*str) + 1, my_strlen((*str) + 1));
      if (result != NULL)
	{
	  free(*str);
	  *str = result;
	}
    }
}

char		**my_parse_args(char *str, char **env)
{
  char		**argv;
  int		i;

  if ((argv = my_split_string(str, " \t\n", 1)) != NULL)
    {
      i = 0;
      while (argv[i] != NULL)
	{
	  if (argv[i][0] == '$')
	    replace_variable(&argv[i], env);
	  else if (argv[i][0] == '~')
	    replace_home_symbol(&argv[i], env);
	  else if (argv[i][0] == '\'')
	    replace_quotes(&argv[i], env, 0);
	  else if (argv[i][0] == '"')
	    replace_quotes(&argv[i], env, 1);
	  i = i + 1;
	}
    }
  return (argv);
}
