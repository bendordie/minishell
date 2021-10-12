/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onightst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:05:55 by onightst          #+#    #+#             */
/*   Updated: 2021/06/06 17:35:48 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_red_ifelse(t_all *all)
{
	if (!ft_strcmp(all->cm[all->ri]->arg[all->rj], "<"))
	{
		all->cm[all->ri]->redirect[all->rrc] = 1;
		all->rrc++;
		ft_strcpy(all->cm[all->ri]->file[all->rfc],
			all->cm[all->ri]->arg[all->rj + 1]);
		all->rfc++;
	}
	else if (!ft_strcmp(all->cm[all->ri]->arg[all->rj], ">"))
	{
		all->cm[all->ri]->redirect[all->rrc] = 2;
		all->rrc++;
		ft_strcpy(all->cm[all->ri]->file[all->rfc],
			all->cm[all->ri]->arg[all->rj + 1]);
		all->rfc++;
	}
	else if (!ft_strcmp(all->cm[all->ri]->arg[all->rj], ">>"))
	{
		all->cm[all->ri]->redirect[all->rrc] = 3;
		all->rrc++;
		ft_strcpy(all->cm[all->ri]->file[all->rfc],
			all->cm[all->ri]->arg[all->rj + 1]);
		all->rfc++;
	}
}

void	ft_redirections(t_all *all, int sc)
{
	all->ri = 0;
	all->rj = 0;
	all->rrc = 0;
	all->rfc = 0;
	while (all->cm[all->ri]->on == 1)
	{
		all->rj = 0;
		while (all->cm[all->ri]->arg[all->rj][0] != '\0')
		{
			ft_red_ifelse(all);
			all->rj++;
		}
		all->rrc = 0;
		all->rfc = 0;
		all->ri++;
	}
}
