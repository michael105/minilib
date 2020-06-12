/*
** my_array_from_array.c for arraymy in ./src/arraymy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Nov 10 17:19:40 2012 ivan ignatiev
** Last update Sun Nov 11 18:31:28 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"stringmy.h"
#include	"arraymy.h"

char		**my_array_from_array(char **arr)
{
  char		**new_array;
  int		len;
  int		str_len;
  int		i;

  len = my_array_length(arr);
  new_array = (char**)malloc(sizeof(char*) * (len + 1));
  if (new_array != NULL)
    {
      i = 0;
      while (i < len)
	{
	  str_len = my_strlen(arr[i]);
	  new_array[i] = (char*)malloc(sizeof(char) * (str_len + 1));
	  if (new_array[i] != NULL)
	    my_strcpy(new_array[i], arr[i]);
	  i = i + 1;
	}
      new_array[i] = NULL;
    }
  return (new_array);
}
