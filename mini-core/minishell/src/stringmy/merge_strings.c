/*
** merge_strings.c for stringmy in ./src/stringmy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sun Nov 11 15:37:07 2012 ivan ignatiev
** Last update Sun Nov 11 18:41:44 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"stringmy.h"

char		*merge_strings(char *str, char *plus, int n)
{
  char		*result;
  int		total_len;

  total_len = my_strlen(str) + my_strlen(plus) + 1;
  result = (char*)malloc(sizeof(char) * total_len);
  if (result != NULL)
    {
      if (str != NULL)
	{
	  my_strcpy(result, str);
	  my_strncat(result, plus, n);
	  free(str);
	}
      else
	my_strncpy(result, plus, n);
      return (result);
    }
  return (str);
}
