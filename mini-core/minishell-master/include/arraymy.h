/*
** arraymy.h for arraymy in ./include
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Nov 10 19:55:29 2012 ivan ignatiev
** Last update Sun Dec  2 17:52:08 2012 ivan ignatiev
*/

#ifndef ARRAYMY_H_
# define ARRAYMY_H_

char	**my_array_from_array(char **arr);
char	**my_split_string(char *str, char *separator,
			  int quotes_mode);
char	**my_add_to_array(char *str, char **arr);
void	my_print_array(char **arr);
int	my_free_array(char **arr);
int	my_array_length(char **arr);
char	**my_remove_from_array(int rem, char **arr);

#endif
