/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cycle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onightst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:42:06 by onightst          #+#    #+#             */
/*   Updated: 2021/06/07 17:12:11 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_print_char(t_all *all)
{
	if (all->str[0] >= 32 && all->str[0] <= 126)
	{
		all->prompt++;
		write(1, &all->str[0], 1);
		if (all->str[0] != '\n')
		{
			all->ready[all->i] = all->str[0];
			all->i++;
		}
	}
	free(all->live);
	all->live = ft_strdup(all->ready);
}

void	ft_backs_key(t_all *all)
{
	if (all->prompt > 0)
	{
		tputs(cursor_left, 1, ft_putint);
		tputs(tgetstr("dc", 0), 1, ft_putint);
		tputs(tgetstr("cd", 0), 1, ft_putint);
		all->i--;
		all->ready[all->i] = '\0';
		all->prompt--;
	}
}

void	ft_up_key(t_all *all, char **hist)
{
	if (all->j > 0)
	{
		tputs(restore_cursor, 1, ft_putint);
		tputs(tigetstr("ed"), 1, ft_putint);
		all->prompt = 0;
		write(1, "minibender! ", 12);
		all->j--;
		write(1, hist[all->j], ft_strlen(hist[all->j]) - 1);
		ft_bzero(all->ready, 1000);
		ft_strcpy(all->ready, hist[all->j]);
		all->ready[ft_strlen(hist[all->j]) - 1] = '\0';
		all->i = ft_strlen(hist[all->j]) - 1;
		all->prompt = ft_strlen(hist[all->j]) - 1;
		ft_bzero(all->arrow, 3);
		ft_bzero(all->str, 1);
	}
}

void	ft_read_from_0(t_all *all)
{
	int	n;

	read(0, all->str, 1);
	ioctl(0, FIONREAD, &n);
	if (n > 0)
	{
		read(0, all->arrow, 2);
		all->arrow[2] = 0;
	}
	all->str[1] = 0;
}

void	ft_print_cycle(t_all *all, char **hist)
{
	all->cringe = 0;
	while ((ft_strcmp(all->str, "\n")
			&& ft_strcmp(all->str, "\4")) || all->cringe == 0)
	{
		ft_read_from_0(all);
		if (!ft_strcmp(all->arrow, "[A"))
			ft_up_key(all, hist);
		else if (!ft_strcmp(all->arrow, "[B"))
			ft_down_key(all, hist);
		else if (!ft_strcmp(all->str, "\177"))
			ft_backs_key(all);
		else if (!ft_strcmp(all->str, "\3"))
		{
			g_global_error = 1;
			all->qew = 1;
			break ;
		}
		else
			ft_print_char(all);
		ft_exit_signal_key(all);
		all->cringe = 1;
	}
	write(1, "\n", 1);
}
