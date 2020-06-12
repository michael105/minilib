/*
** my_strncat.c for stringmy in ./src/stringmy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Tue Oct  9 11:46:21 2012 ivan ignatiev
** Last update Sun Nov 11 12:44:53 2012 ivan ignatiev
*/

#include	"stringmy.h"

char		*my_strncat(char *dest, char *src, int nb)
{
  int		i;
  int		dest_len;

  dest_len = my_strlen(dest);
  i = 0;
  while (src[i] != '\0' && i < nb)
    {
      dest[dest_len + i] = src[i];
      ++i;
    }
  dest[dest_len + i] = '\0';
  return (dest);
}
