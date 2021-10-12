/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minibender_preparations.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onightst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:16:45 by onightst          #+#    #+#             */
/*   Updated: 2021/06/06 17:18:35 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_malloc_all(t_all *all)
{
	all->command = malloc(1000 * sizeof(char));
	all->arg1 = malloc(1000 * sizeof(char));
	all->ready = malloc(1000 * sizeof(char));
	all->str = malloc(2 * sizeof(char));
	all->arrow = malloc(3 * sizeof(char));
}

void	ft_make_env_arr(char **envp, char ***enena, t_all *all)
{
	int	i;

	i = 0;
	while (envp[i] != 0)
		i++;
	*enena = ft_calloc(i + 1, sizeof(char *));
	all->ee = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (envp[i] != 0)
	{
		all->ee[i] = ft_strdup(envp[i]);
		(*enena)[i] = ft_strdup(envp[i]);
		i++;
	}
	(*enena)[i] = 0;
}

void	ft_print_prepare(t_all *all)
{
	all->qew = 0;
	tputs(save_cursor, 1, ft_putint);
	ft_bzero(all->ready, 1000);
	ft_bzero(all->command, 1000);
	ft_bzero(all->arg1, 1000);
	all->i = 0;
	all->prompt = 0;
	write(1, "minibender! ", 12);
	free(all->live);
	all->live = ft_strdup("");
}

void	ft_count_hist(t_all *all)
{
	char	n[1];

	all->hns = 0;
	all->hfd = open(all->log, O_RDWR | O_CREAT, 0777);
	while (read(all->hfd, n, 1))
	{
		if (n[0] == '\n')
			all->hns++;
	}
	close(all->hfd);
}

int	ft_make_hist(char ***hist, t_all *all)
{
	int		j;
	char	n[1];
	char	ins[1000];
	int		insc;

	j = 0;
	insc = 0;
	ft_bzero(ins, 1000);
	ft_count_hist(all);
	*hist = ft_calloc(all->hns + 1, sizeof(char *));
	all->hfd = open(all->log, O_RDWR | O_CREAT, 0777);
	while (read(all->hfd, n, 1))
	{
		ins[insc++] = n[0];
		if (n[0] == '\n')
		{
			(*hist)[j] = ft_strdup(ins);
			insc = 0;
			j++;
			ft_bzero(ins, 1000);
		}
	}
	(*hist)[j] = 0;
	close(all->hfd);
	return (j);
}
