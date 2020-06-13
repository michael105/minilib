/*
** my_putchar.c for my_putchar in /home/ignati_i//test_c/lib/my
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Oct 22 10:02:19 2012 ivan ignatiev
** Last update Sat Nov 10 20:38:05 2012 ivan ignatiev
*/

#include	<unistd.h>
#include	"stringmy.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}
