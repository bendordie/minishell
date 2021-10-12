/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onightst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:04:14 by onightst          #+#    #+#             */
/*   Updated: 2021/06/06 17:11:14 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_bzero_struct_1(t_all *all, int i)
{
	int	j;

	j = 0;
	while (j < 100)
	{
		free(all->cm[i]->arg[j]);
		j++;
	}
	free(all->cm[i]->arg);
}

void	ft_bzero_struct(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < 100)
	{
		free(all->cm[i]->redirect);
		j = 0;
		while (all->cm[i]->arg[j])
		{
			free(all->cm[i]->arg[j]);
			j++;
		}
		j = 0;
		while (all->cm[i]->file[j])
		{
			free(all->cm[i]->file[j]);
			j++;
		}
		free(all->cm[i]->arg);
		free(all->cm[i]->file);
		free(all->cm[i]);
		i++;
	}
	free(all->cm);
}
