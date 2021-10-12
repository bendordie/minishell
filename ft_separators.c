/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onightst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:09:15 by onightst          #+#    #+#             */
/*   Updated: 2021/06/06 17:41:36 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_one_slashe(t_all *all, char *line)
{
	all->cm[all->sc]->on = 1;
	all->cm[all->sc + 1]->on = 0;
	all->pi++;
	all->cm[all->sc]->arg[all->ac][all->count] = line[all->pi];
	all->count++;
	all->pi++;
}

void	ft_slashes(t_all *all, char *line)
{
	all->cm[all->sc]->on = 1;
	all->cm[all->sc + 1]->on = 0;
	all->cm[all->sc]->arg[all->ac][all->count] = line[all->pi];
	all->count++;
	all->pi += 2;
}

void	ft_space(t_all *all, char *line)
{
	if (all->cm[all->sc]->arg[all->ac][all->count - 1] != 0)
	{
		all->count = 0;
		all->ac++;
		all->pi++;
		while (line[all->pi] == ' ')
			all->pi++;
	}
	else
		all->pi++;
}

void	ft_separator(t_all *all, char *line)
{
	all->cm[all->sc]->pipe = 0;
	all->sc++;
	all->ac = 0;
	all->rc = 0;
	all->count = 0;
	all->pi++;
}

void	ft_poip(t_all *all, char *line)
{
	all->cm[all->sc]->pipe = 1;
	all->sc++;
	all->cm[all->sc]->pipe = 1;
	all->ac = 0;
	all->rc = 0;
	all->count = 0;
	all->pi++;
	all->cm[all->sc]->on = 1;
}
