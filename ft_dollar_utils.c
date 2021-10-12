/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:38:14 by cshells           #+#    #+#             */
/*   Updated: 2021/06/07 18:01:22 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_alone_dollar_else(t_all *all, char *line)
{
	if (line[all->pi + 1] == '?')
		ft_doll_que(all);
	else if (line[all->pi + 1] >= '0' && line[all->pi + 1] <= '9')
		all->pi += 2;
	else
	{
		all->pi++;
		while (line[all->pi] && line[all->pi] != ';' && line[all->pi] != '|'
			&& line[all->pi] != ' ' && line[all->pi] != '$')
		{
			if (line[all->pi] == '(' || line[all->pi] == ')')
			{
				printf("minibender: syntax error near unexpected token `%c'\n",
					line[all->pi]);
				all->qew = 1;
				break ;
			}
			all->pi++;
		}
	}
}
