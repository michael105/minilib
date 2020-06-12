/*
** my_print_array.c for arraymy in ./src/arraymy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Nov 10 21:45:10 2012 ivan ignatiev
** Last update Sun Nov 11 10:28:03 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"stringmy.h"

void		my_print_array(char **arr)
{
  int		i;

  i = 0;
  while (arr[i] != NULL)
    {
      my_putstr(arr[i]);
      my_putchar('\n');
      i = i + 1;
    }
}
