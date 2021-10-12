/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onightst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:54:29 by onightst          #+#    #+#             */
/*   Updated: 2021/06/07 20:26:16 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_putint(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

void	ft_clean_hist(char ***hist)
{
	int	j;

	j = 0;
	while ((*hist)[j])
	{
		free((*hist)[j]);
		j++;
	}
	free(*hist);
}

void	ft_add_hist(t_all *all, char ***hist)
{
	int	fd;

	if (ft_strcmp("", all->ready))
	{
		fd = open(all->log, O_WRONLY | O_APPEND | O_CREAT, 0777);
		write(fd, all->ready, ft_strlen(all->ready));
		write(fd, "\n", 1);
		close(fd);
		ft_clean_hist(hist);
		all->j = ft_make_hist(hist, all);
	}
}

void	ft_shell_init(t_all *all, char **envp, char ***enena, char ***hist)
{
	char	*term_name;

	term_name = getenv("TERM");
	ft_malloc_all(all);
	ft_make_env_arr(envp, enena, all);
	ft_make_logname(all);
	all->j = 0;
	all->j = ft_make_hist(hist, all);
	tcgetattr(0, all->term);
	tcgetattr(0, all->term_n);
	all->term->c_lflag &= ~(ECHO);
	all->term->c_lflag &= ~(ICANON);
	all->term->c_lflag &= ~(ISIG);
	tcsetattr(0, TCSANOW, all->term);
	tgetent(0, term_name);
	ft_signal_init(0);
	ft_increase_shlvl(&all->ee);
}

int	main(int argc, char **argv, char **envp)
{
	char			**hist;
	char			**enena;
	struct termios	term;
	struct termios	term_n;
	t_all			*all;

	all = malloc(sizeof(t_all));
	all->term = &term;
	all->term_n = &term_n;
	ft_shell_init(all, envp, &enena, &hist);
	while (ft_strcmp(all->str, "\4"))
	{
		tcsetattr(0, TCSANOW, all->term);
		ft_print_prepare(all);
		ft_print_cycle(all, hist);
		tcsetattr(0, TCSANOW, all->term_n);
		ft_parse(all->ready, all, enena);
		if (all->qew == 1)
			continue ;
		ft_execute(all, enena);
		ft_bzero_struct(all);
		ft_add_hist(all, &hist);
		tcsetattr(0, TCSANOW, all->term);
	}
	return (0);
}
