/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doll_que.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 20:59:47 by cshells           #+#    #+#             */
/*   Updated: 2021/06/07 17:04:34 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_doll_que(t_all *all)
{
	char	*global;
	int		i;

	all->pi += 2;
	i = 0;
	global = ft_itoa(g_global_error);
	while (global[i])
	{
		all->cm[all->sc]->arg[all->ac][all->count] = global[i];
		all->count++;
		i++;
	}
}
