/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_for_cut.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onightst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:59:49 by onightst          #+#    #+#             */
/*   Updated: 2021/06/07 17:03:30 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_cut_e_if(t_all *all)
{
	if (!ft_strcmp(all->cm[all->ci]->arg[all->cj], "<")
		|| !ft_strcmp(all->cm[all->ci]->arg[all->cj], ">")
		|| !ft_strcmp(all->cm[all->ci]->arg[all->cj], ">>"))
		return (1);
	return (0);
}

int	ft_cut_e_ife(t_all *all)
{
	if (all->cj > 0
		&& (!ft_strcmp(all->cm[all->ci]->arg[all->cj - 1], "<")
			|| !ft_strcmp(all->cm[all->ci]->arg[all->cj - 1], ">")
			|| !ft_strcmp(all->cm[all->ci]->arg[all->cj - 1], ">>")))
		return (1);
	return (0);
}
