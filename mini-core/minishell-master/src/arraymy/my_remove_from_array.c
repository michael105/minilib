/*
** my_remove_from_array.c for arraymy in ./src/arraymy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Nov 10 17:31:04 2012 ivan ignatiev
** Last update Sun Nov 11 18:31:10 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"stringmy.h"
#include	"arraymy.h"

char		**copy_array_without(int rem, char **new_arr, char **arr, int len)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i < len)
    {
      if (i != rem)
	{
	  new_arr[j] = (char*)malloc(sizeof(char) * (my_strlen(arr[i]) + 1));
	      if (new_arr[j])
		{
		  my_strcpy(new_arr[j], arr[i]);
		  j = j + 1;
		}
	}
      i = i + 1;
    }
  new_arr[j] = NULL;
  return (new_arr);
}

char		**my_remove_from_array(int rem, char **arr)
{
  int		len;
  char		**new_arr;

  new_arr = NULL;
  if (arr != NULL)
    {
      len = my_array_length(arr);
      new_arr = (char**)malloc(sizeof(char*) * (len));
      new_arr = copy_array_without(rem, new_arr, arr, len);
      my_free_array(arr);
    }
  return (new_arr);
}

