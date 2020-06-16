/*
** my_strcmp.c for stringmy in ./src/stringmy/
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Oct  8 11:00:05 2012 ivan ignatiev
** Last update Sun Nov 11 14:20:04 2012 ivan ignatiev
*/

#include "stringmy.h"

int	my_strcmp(char *s1, char *s2)
{
  int	result;
  int	i;

  result = 0;
  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && !result)
    {
      result = s1[i] - s2[i];
      i++;
    }
  if (s1[i] == '\0' && s2[i] != '\0')
    return (-100);
  else if (s2[i] == '\0' && s1[i] != '\0')
    return (100);
  return (result);
}
