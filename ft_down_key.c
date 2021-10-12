/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_down_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onightst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:45:37 by onightst          #+#    #+#             */
/*   Updated: 2021/06/06 17:49:51 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_down_key_else(t_all *all)
{
	tputs(restore_cursor, 1, ft_putint);
	tputs(tigetstr("ed"), 1, ft_putint);
	all->prompt = 0;
	write(1, "minibender! ", 12);
	write(1, all->live, ft_strlen(all->live));
	ft_bzero(all->ready, 1000);
	ft_strcpy(all->ready, all->live);
	all->i = ft_strlen(all->live);
	all->prompt = ft_strlen(all->live);
	ft_bzero(all->arrow, 3);
	ft_bzero(all->str, 1);
}

void	ft_down_key(t_all *all, char **hist)
{
	if (hist[all->j] != 0)
	{
		all->j++;
		if (hist[all->j] != 0)
		{
			tputs(restore_cursor, 1, ft_putint);
			tputs(tigetstr("ed"), 1, ft_putint);
			all->prompt = 0;
			write(1, "minibender! ", 12);
			write(1, hist[all->j], ft_strlen(hist[all->j]) - 1);
			ft_bzero(all->ready, 1000);
			ft_strcpy(all->ready, hist[all->j]);
			all->i = ft_strlen(hist[all->j]) - 1;
			all->prompt = ft_strlen(hist[all->j]) - 1;
			ft_bzero(all->arrow, 3);
			ft_bzero(all->str, 1);
		}
		else
			ft_down_key_else(all);
	}
}
