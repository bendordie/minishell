/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_logname.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:22:50 by cshells           #+#    #+#             */
/*   Updated: 2021/06/07 20:25:50 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_make_logname(t_all *all)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (ft_strncmp(all->ee[i], "LOGNAME", 7) != 0)
		i++;
	while (all->ee[i][j] != '=')
		j++;
	j++;
	all->log = ft_strdup(&all->ee[i][j]);
	tmp = all->log;
	all->log = ft_strjoin("/Users/", all->log);
	free(tmp);
	tmp = all->log;
	all->log = ft_strjoin(all->log, "/hist.txt");
	free(tmp);
}
