/*
** my_strncmp.c for stringmy in ./src/stringmy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Oct  8 11:00:05 2012 ivan ignatiev
** Last update Sat Nov 10 20:35:39 2012 ivan ignatiev
*/

#include	"stringmy.h"

int		my_strncmp(char *s1, char *s2, int n)
{
  int		result;
  int		i;

  if (n > 0)
    {
      result = 0;
      i = 0;
      while (i < n
	     && s1[i] != '\0'
	     && s2[i] != '\0'
	     && !result)
	{
	  result = s1[i] - s2[i];
	  i++;
	}
      if (i < n - 1 && s1[i] == '\0' && s2[i] != '\0')
	return (-100);
      else if (i < n - 1 && s2[i] == '\0' && s1[i] != '\0')
	return (100);
      else
	return (result);
    }
  return (0);
}
