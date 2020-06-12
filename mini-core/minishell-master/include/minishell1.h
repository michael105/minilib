/*
** minishell1.h for minishell1 in ./include
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Nov 10 20:14:11 2012 ivan ignatiev
** Last update Sun Dec  2 15:10:37 2012 ivan ignatiev
*/

#ifndef	MINISHELL1_H_
# define MINISHELL1_H_

int	exec_command_ior(char *cmd, char ***env, int idf, int odf);
int	exec_command_pipe(char *cmd, char ***env);
int	exec_cmds_by_order(char *cmd, char ***env);
int	execute_command(char *command, char ***env, int, int);
int	manage_options(int argc, char **argv);

char	*get_bin_path(char *filename, char **env);
char	*get_home_dir(char **env);

char	**my_parse_args(char *str, char **env);

int	my_getenv(char *name, char **env);
char	**my_setenv(char *name, char *value, char **env);
char	**my_unsetenv(char *name, char **env);

int	command_exit(char **argv, char **env);
int	command_setenv(char **argv, char ***env);
int	command_unsetenv(char **argv, char ***env);
int	command_cd(char **argv, char ***env);
int	command_env(char **argv, char ***env);

#endif /* MINISHELL1_H_ */
