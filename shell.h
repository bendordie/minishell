/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:40:57 by cshells           #+#    #+#             */
/*   Updated: 2021/06/07 20:18:04 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <sys/ioctl.h>
# include <termios.h>
# include "libft/libft.h"
# include <term.h>
# include "gnl/get_next_line.h"
# include <dirent.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <sys/param.h>
# include <sys/stat.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>

typedef struct s_cmd
{
	int				pipe;
	int				exit_status;
	int				*redirect;
	int				on;
	char			**arg;
	char			**file;
}					t_cmd;

typedef struct s_pipe
{
	int				**fd_arr;
	pid_t			*pid_arr;
}					t_pipe;

typedef struct s_all
{
	int				flag;
	int				qew;
	int				prompt;
	int				i;
	int				j;
	int				count;
	int				enn;
	int				sc;
	int				ac;
	int				rc;
	int				fc;
	int				pi;
	int				itf;
	int				check;
	int				w;
	int				ri;
	int				rj;
	int				rrc;
	int				rfc;
	int				ci;
	int				cj;
	int				cr;
	int				cuts;
	int				hfd;
	int				hns;
	int				cringe;
	char			*arrow;
	char			*arg1;
	char			**ace;
	char			*command;
	char			*dollar;
	char			**ee;
	char			*live;
	char			*ready;
	char			*str;
	t_cmd			**cm;
	struct termios	*term_n;
	struct termios	*term;
	char			*log;
}					t_all;

int		g_global_error;

int		ft_check_quotes_d(char *line, int i);
int		ft_check_quotes_s(char *line, int i);
int		ft_cut_e_if(t_all *all);
int		ft_cut_e_ife(t_all *all);
int		ft_dollar(char *line, int i, char **env);
int		ft_make_hist(char ***hist, t_all *all);
int		ft_putint(int c);
void	ft_alone_dollar_else(t_all *all, char *line);
void	ft_bzero_struct(t_all *all);
void	ft_bzero_struct_1(t_all *all, int i);
void	ft_cal_nums(t_all *all);
void	ft_check_redir0(t_all *all);
void	ft_count_hist(t_all *all);
void	ft_cut_ends(t_all *all);
void	ft_dolce(char *line, int i, char **env, char **check);
void	ft_doll_que(t_all *all);
void	ft_double_quote(t_all *all, char *line, char **env);
void	ft_down_key(t_all *all, char **hist);
void	ft_exit_signal_key(t_all *all);
void	ft_make_env_arr(char **envp, char ***enena, t_all *all);
void	ft_make_logname(t_all *all);
void	ft_make_struct(char *line, char **env, t_all *all);
void	ft_malloc_all(t_all *all);
void	ft_parse(char *line, t_all *all, char **env);
void	ft_print_cycle(t_all *all, char **hist);
void	ft_print_prepare(t_all *all);
void	ft_redirections(t_all *all, int sc);
void	ft_one_slashe(t_all *all, char *line);
void	ft_poip(t_all *all, char *line);
void	ft_separator(t_all *all, char *line);
void	ft_slashes(t_all *all, char *line);
void	ft_solo_quote(t_all *all, char *line);
void	ft_space(t_all *all, char *line);
int		ft_env_key_length(char *arg);
int		ft_export_identifier_validation(char *arg);
int		ft_find_env_key(char *arg, char **env, int equal_pos);
int		ft_identifier_validation(char *arg);
int		ft_is_special(t_cmd *cmd);
int		ft_pipe(t_all *all, int begin, char **env, int cmd_count);
int		ft_redirect(t_cmd *cmd, char **env);
int		ft_run_command(t_cmd *cmd, char **env);
int		ft_strcmp(char *s1, char *s2);
char	**ft_edit_env(char *arg, char **env, int append);
char	*ft_get_env(char *key, char **env);
char	**ft_list_to_array(t_list **begin_list, int num);
char	*ft_strcpy(char *dest, char *src);
void	ft_cd(char **argv, char ***env, int fork);
void	ft_dollar_question(void);
void	ft_echo(char **argv);
void	ft_env(char **env);
void	ft_error(char *program_name, char *err, char *arg, int err_code);
void	ft_execute(t_all *all, char **enena);
void	ft_exit(char **arg);
void	ft_export(char **arg, char ***env, int fork);
void	ft_export_output(char **env);
void	ft_free_double_array(char **arr);
void	ft_increase_shlvl(char ***env);
void	ft_oldpwd_update(char *oldpwd, char ***env);
void	ft_pipe_mem_cleaner(pid_t *pid_arr, int **fd_arr, int size);
void	ft_pwd(void);
void	ft_pwd_update(char ***env);
void	ft_run_binary(t_cmd *cmd, char **env);
void	ft_run_special(t_cmd *cmd, char ***env);
void	ft_signal_handler(int status);
void	ft_signal_init(int condition);
void	ft_sort_array(char **array);
void	ft_unset(char **argv, char ***env, int fork);
size_t	ft_strlen_to_char(char *s, char c);
t_list	*ft_array_to_list(char **array);

#endif
