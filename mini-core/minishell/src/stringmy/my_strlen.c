/*
** my_strlen.c for stringmy in ./src/stringmy/
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Thu Oct  4 10:17:59 2012 ivan ignatiev
** Last update Sun Nov 11 12:49:10 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"stringmy.h"

int		my_strlen(char *str)
{
  int		len;
  char		*buf;

  if (str == NULL)
    return (0);
  buf = str;
  len = 0;
  while (*buf != '\0')
    {
      len++;
      buf++;
    }
  return (len);
}
