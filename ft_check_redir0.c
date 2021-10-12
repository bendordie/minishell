/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redir0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onightst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 21:12:59 by onightst          #+#    #+#             */
/*   Updated: 2021/06/02 21:23:46 by onightst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_check_redir0(t_all *all)
{
	int		i;
	char	*tmp;

	i = 0;
	while (all->cm[i]->on == 1)
	{
		if (!ft_strcmp(all->cm[i]->arg[0], "/<")
			|| !ft_strcmp(all->cm[i]->arg[0], "/>")
			|| !ft_strcmp(all->cm[i]->arg[0], "/<<"))
		{
			tmp = all->cm[i]->arg[0];
			all->cm[i]->arg[0] = ft_strdup("/");
			free(tmp);
		}
		i++;
	}
}
