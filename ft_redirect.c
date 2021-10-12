/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 21:15:52 by cshells           #+#    #+#             */
/*   Updated: 2021/05/30 20:20:31 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_redirect_cycle(t_cmd *cmd, int *fd_0, int *fd_1)
{
	int	i;

	i = 0;
	while (ft_strlen(cmd->file[i]))
	{
		if (cmd->redirect[i] == 2)
			*fd_1 = open(cmd->file[i], O_RDWR | O_CREAT \
					| O_TRUNC, S_IRUSR | S_IWUSR);
		else if (cmd->redirect[i] == 3)
			*fd_1 = open(cmd->file[i], O_RDWR | O_CREAT \
					| O_APPEND, S_IRUSR | S_IWUSR);
		else
			*fd_0 = open(cmd->file[i], O_RDONLY);
		if (*fd_0 < 0 || *fd_1 < 0)
			ft_error(0, strerror(errno), cmd->file[i], errno);
		if (cmd->file[i + 1])
		{
			if (*fd_1
				&& (cmd->redirect[i + 1] == 2 || cmd->redirect[i + 1] == 3))
				close(*fd_1);
			if (*fd_0 && cmd->redirect[i + 1] == 1)
				close(*fd_0);
		}
		i++;
	}
}

int	ft_redirect(t_cmd *cmd, char **env)
{
	int	fd_0;
	int	fd_1;

	fd_0 = 0;
	fd_1 = 0;
	ft_redirect_cycle(cmd, &fd_0, &fd_1);
	if (fd_1 > 0)
		dup2(fd_1, 1);
	if (fd_0 > 0)
		dup2(fd_0, 0);
	ft_run_command(cmd, env);
	return (0);
}
