/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onightst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:09:27 by onightst          #+#    #+#             */
/*   Updated: 2021/06/06 17:18:07 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_cal_nums(t_all *all)
{
	all->count = 0;
	all->enn = -1;
	all->sc = 0;
	all->ac = 0;
	all->rc = 0;
	all->fc = 0;
	all->w = 0;
	all->pi = 0;
}

void	ft_make_struct(char *line, char **env, t_all *all)
{
	int	i;
	int	j;

	i = 0;
	all->cm = ft_calloc(100, sizeof(t_cmd *));
	while (i < 100)
	{
		all->cm[i] = malloc(sizeof(t_cmd));
		all->cm[i]->arg = ft_calloc(1000, sizeof(char *));
		all->cm[i]->file = ft_calloc(1000, sizeof(char *));
		all->cm[i]->redirect = ft_calloc(1000, sizeof(int));
		j = 0;
		while (j < 100)
		{
			all->cm[i]->arg[j] = ft_calloc(1000, sizeof(char));
			all->cm[i]->file[j] = ft_calloc(1000, sizeof(char));
			j++;
		}
		i++;
	}
}

void	ft_cut_ends_2(t_all *all)
{
	all->ace = ft_calloc(all->cj + 1 - all->cuts, sizeof(char *));
	all->cj = 0;
	all->cr = 0;
	while (all->cm[all->ci]->arg[all->cj][0] != '\0')
	{
		if (!ft_strcmp(all->cm[all->ci]->arg[all->cj], "<")
			|| !ft_strcmp(all->cm[all->ci]->arg[all->cj], ">")
			|| !ft_strcmp(all->cm[all->ci]->arg[all->cj], ">>"))
			all->cj++;
		else if (all->cj > 0
			&& (!ft_strcmp(all->cm[all->ci]->arg[all->cj - 1], "<")
				|| !ft_strcmp(all->cm[all->ci]->arg[all->cj - 1], ">")
				|| !ft_strcmp(all->cm[all->ci]->arg[all->cj - 1], ">>")))
			all->cj++;
		else
		{
			all->ace[all->cr] = ft_strdup(all->cm[all->ci]->arg[all->cj]);
			all->cj++;
			all->cr++;
		}
	}
	ft_bzero_struct_1(all, all->ci);
	all->cm[all->ci]->arg = all->ace;
	all->ci++;
}

int	ft_cut_ends_1(t_all *all)
{
	while (all->cm[all->ci]->arg[all->cj][0] != '\0')
	{
		if (ft_cut_e_if(all))
		{
			all->cuts++;
			all->cj++;
			if (!all->cm[all->ci]->arg[all->cj][0])
			{
				printf("minibender!: \
						syntax error near unexpected token `newline'\n");
				all->qew = 1;
				return (0);
			}
		}
		else if (ft_cut_e_ife(all))
		{
			all->cuts++;
			all->cj++;
		}
		else
			all->cj++;
	}
	return (1);
}

void	ft_cut_ends(t_all *all)
{
	all->ci = 0;
	while (all->cm[all->ci]->on == 1)
	{
		all->cj = 0;
		all->cuts = 0;
		if (!ft_cut_ends_1(all))
			return ;
		ft_cut_ends_2(all);
	}
}
