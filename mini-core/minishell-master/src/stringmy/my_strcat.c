/*
** my_strcat.c for stringmy in ./src/stringmy/
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Tue Oct  9 11:46:21 2012 ivan ignatiev
** Last update Sat Nov 10 20:34:51 2012 ivan ignatiev
*/

#include	"stringmy.h"

char		*my_strcat(char *dest, char *src)
{
  int		i;
  int		dest_len;

  dest_len = my_strlen(dest);
  i = 0;
  while (src[i] != '\0')
    {
      dest[dest_len + i] = src[i];
      ++i;
    }
  dest[dest_len + i] = '\0';
  return (dest);
}
