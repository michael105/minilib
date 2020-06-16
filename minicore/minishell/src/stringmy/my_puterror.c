/*
** my_putstr.c for stringmy in ./src/stringmy/
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Thu Oct  4 10:07:29 2012 ivan ignatiev
** Last update Sun Nov 11 13:34:08 2012 ivan ignatiev
*/

#include	<unistd.h>
#include	"stringmy.h"

void		my_puterror(char *str)
{
  while (*str != '\0')
    {
      write(2, &(*str), 1);
      str++;
    }
}
