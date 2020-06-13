/*
** my_strncpy.c for stringmy in ./src/stringmy/
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Oct  8 10:11:21 2012 ivan ignatiev
** Last update Sun Nov 11 13:09:30 2012 ivan ignatiev
*/

#include	"stringmy.h"

char		*my_strncpy(char *dest, char *src, int n)
{
  int		i;

  i = 0;
  while (i < n && src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  while (i <= n)
    {
      dest[i] = '\0';
      i++;
    }
  return (dest);
}
