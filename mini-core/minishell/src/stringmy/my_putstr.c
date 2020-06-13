/*
** my_putstr.c for stringmy in ./src/stringmy/
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Thu Oct  4 10:07:29 2012 ivan ignatiev
** Last update Sat Nov 10 20:33:50 2012 ivan ignatiev
*/

#include	"stringmy.h"

void		my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str++;
    }
}
