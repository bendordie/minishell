/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:25:55 by cshells           #+#    #+#             */
/*   Updated: 2021/06/07 17:07:02 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_pipeline(t_all *all, int *k, int *m)
{
	while (all->cm[*k]->pipe)
	{
		(*k)++;
		(*m)++;
	}
	ft_pipe(all, *k - *m, all->ee, *m);
}

void	ft_if_redirect(t_cmd *cm, char **env)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		ft_signal_init(1);
		ft_redirect(cm, env);
	}
	waitpid(pid, &cm->exit_status, WUNTRACED);
}

void	ft_if_solo_cmd(t_cmd *cm, char **env)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		ft_signal_init(1);
		ft_run_command(cm, env);
	}
	waitpid(pid, &cm->exit_status, WUNTRACED);
}

void	ft_not_pipe(t_all *all, int *k)
{
	if (ft_is_special(all->cm[*k]))
		ft_run_special(all->cm[*k], &(all->ee));
	else
	{
		if (all->cm[*k]->redirect[0])
			ft_if_redirect(all->cm[*k], all->ee);
		else
			ft_if_solo_cmd(all->cm[*k], all->ee);
	}
	ft_signal_handler(all->cm[*k]->exit_status);
	(*k)++;
}

void	ft_execute(t_all *all, char **enena)
{
	int	k;
	int	m;

	k = 0;
	m = 0;
	if (all->cm[k] && all->cm[k]->on == 1)
	{
		while (all->cm[k]->on == 1)
		{
			ft_bzero_struct(all);
			ft_parse(all->ready, all, enena);
			if (all->cm[k]->pipe)
				ft_pipeline(all, &k, &m);
			else
				ft_not_pipe(all, &k);
		}
	}
}
