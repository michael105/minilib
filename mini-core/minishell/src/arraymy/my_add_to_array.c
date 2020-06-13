/*
** my_add_to_array.c for arraymy in ./src/arraymy/
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Nov 10 17:22:58 2012 ivan ignatiev
** Last update Sun Nov 11 10:40:46 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"arraymy.h"

char		**malloc_from_arr(char *str, char **arr)
{
  int		i;
  char		**new_arr;

  i = 0;
  while (arr[i] != NULL)
    i = i + 1;
  new_arr = (char**)malloc(sizeof(char*) * (i + 2));
  if (new_arr == NULL)
    return (arr);
  i = 0;
  while (arr[i] != NULL)
    {
      new_arr[i] = arr[i];
      i = i + 1;
    }
  free(arr);
  new_arr[i] = str;
  new_arr[i + 1] = NULL;
  return (new_arr);
}

char		**my_add_to_array(char *str, char **arr)
{
  char		**new_arr;

  if (arr == NULL)
    {
      new_arr = (char**)malloc(sizeof(char*) * 2);
      if (new_arr == NULL)
	return (arr);
      new_arr[0] = str;
      new_arr[1] = NULL;
    }
  else
    return (malloc_from_arr(str, arr));
  return (new_arr);
}
