/*
** my_strcpy.c for stringmy in ./src/stringmy/
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Oct  8 09:57:13 2012 ivan ignatiev
** Last update Sat Nov 10 20:36:19 2012 ivan ignatiev
*/

#include	"stringmy.h"

char		*my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

