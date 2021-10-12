/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:34:07 by cshells           #+#    #+#             */
/*   Updated: 2021/06/07 18:45:41 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_allocate_memory(t_pipe *p, int cmd_count)
{
	int	i;

	p->pid_arr = (pid_t *)malloc(sizeof(pid_t) * (cmd_count + 1));
	p->fd_arr = (int **)malloc(sizeof(int *) * cmd_count);
	i = 0;
	while (i < cmd_count - 1)
	{
		p->fd_arr[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	ft_bzero(p->pid_arr, cmd_count + 1);
	p->fd_arr[cmd_count - 1] = 0;
}

void	ft_close_fd_arr(int **fd_arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		close(fd_arr[i][0]);
		close(fd_arr[i][1]);
		i++;
	}
}

void	ft_dup_n_close_fds(t_pipe *p, int cmd_count, int *i, int *j)
{
	if (*i == 0)
	{
		dup2(p->fd_arr[*j][1], 1);
		ft_close_fd_arr(p->fd_arr, cmd_count - 1);
	}
	else if (*i != cmd_count - 1)
	{
		dup2(p->fd_arr[*j - 1][0], 0);
		dup2(p->fd_arr[*j][1], 1);
		ft_close_fd_arr(p->fd_arr, cmd_count - 1);
	}
	else
	{
		dup2(p->fd_arr[*j - 1][0], 0);
		ft_close_fd_arr(p->fd_arr, cmd_count - 1);
	}
}

void	ft_pipe_cycle(t_all *all, t_pipe *p, int cmd_count, int begin)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (i < cmd_count)
	{
		j++;
		p->pid_arr[i] = fork();
		if (p->pid_arr[i] == 0)
		{
			ft_signal_init(1);
			ft_dup_n_close_fds(p, cmd_count, &i, &j);
			if (all->cm[begin + i]->redirect[0])
				ft_redirect(all->cm[begin + i], all->ee);
			else
				ft_run_command(all->cm[begin + i], all->ee);
		}
		i++;
	}
}

int	ft_pipe(t_all *all, int begin, char **env, int cmd_count)
{
	int		j;
	int		n;
	t_pipe	p;

	ft_allocate_memory(&p, cmd_count);
	n = 0;
	while (n < cmd_count - 1)
	{
		pipe(p.fd_arr[n]);
		n++;
	}
	ft_pipe_cycle(all, &p, cmd_count, begin);
	ft_close_fd_arr(p.fd_arr, cmd_count - 1);
	j = 0;
	while (j < cmd_count)
	{
		waitpid(p.pid_arr[j], &all->cm[begin + j]->exit_status, WUNTRACED);
		j++;
	}
	ft_pipe_mem_cleaner(p.pid_arr, p.fd_arr, cmd_count);
	return (0);
}
