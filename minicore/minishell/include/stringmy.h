/*
** stringmy.h for my in ./include
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Thu Oct 11 10:10:20 2012 ivan ignatiev
** Last update Sun Nov 11 18:24:27 2012 ivan ignatiev
*/

#ifndef MY_H_
# define MY_H_

void	my_putchar(char c);
void	my_putstr(char *str);
void	my_puterror(char *str);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int n);
int	my_strlen(char *str);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
int	my_strncmp(char *str1, char *str2, int n);
int	my_getnbr(char *str);
int	my_strcmp(char *s1, char *s2);
char	*merge_strings(char *str, char *plus, int n);

#endif /* !MY_H_ */
