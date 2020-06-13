/*
** my_array_length.c for arraymy in ./src/arraymy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sun Nov 11 11:01:13 2012 ivan ignatiev
** Last update Sun Nov 11 11:12:16 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"arraymy.h"

int		my_array_length(char **arr)
{
  int		i;

  if (arr == NULL)
    return (0);
  i = 0;
  while (arr[i] != NULL)
    i = i + 1;
  return (i);
}
