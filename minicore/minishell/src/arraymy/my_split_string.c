/*
** my_split_string.c for arraymy in ./src/arraymy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Nov 10 17:21:23 2012 ivan ignatiev
** Last update Wed Nov 28 12:07:59 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"stringmy.h"
#include	"arraymy.h"

int		is_it_separator(char c, char *separators)
{
  int		i;

  i = 0;
  while (c != separators[i] && separators[i] != '\0')
    i = i + 1;
  if (separators[i] != '\0')
    return (1);
  else
    return (0);
}

char		**add_word(char *str, int count,
			 char **arr)
{
  char		*elem;

  elem = (char*)malloc(sizeof(char) * (count + 1));
  if (elem != NULL)
    {
      my_strncpy(elem, str, count);
      elem[count] = '\0';
      return (my_add_to_array(elem, arr));
    }
  return (arr);
}

char		**handle_quotes(char *str, char **arr, int *i)
{
  int		count;
  int		start;

  count = 1;
  start = *i;
  (*i) = (*i) + 1;
  while (str[*i] != '\0'
	 && str[*i] != '\''
	 && str[*i] != '"')
    {
      count = count + 1;
      (*i) = (*i) + 1;
    }
  return (add_word(str + start, count + 1, arr));
}

char		**my_split_string(char *str, char *separators,
				  int quotes_mode)
{
  int		i;
  int		count;
  int		start;
  char		**arr;
  int		quotes;

  i = 0;
  arr = NULL;
  count = 0;
  quotes = 0;
  while (str[i] != '\0')
    {
      if (!is_it_separator(str[i], separators))
	{
	  if ((i == 0 || is_it_separator(str[i - 1], separators)) && !quotes)
	    start = i;
	  if ((str[i] == '\'' || str[i] == '"') && quotes_mode)
	    quotes = !quotes;
	  count = count + 1;
	}
      else if (quotes)
	count = count + 1;
      else if (!quotes && count > 0 && (arr = add_word(str + start, count, arr)) != NULL)
	count = 0;
      i = i + 1;
    }
  if (count > 0)
    arr = add_word(str + start, count, arr);
  return (arr);
}
