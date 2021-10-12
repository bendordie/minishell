/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_special.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 21:05:11 by cshells           #+#    #+#             */
/*   Updated: 2021/06/07 20:21:58 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_open_files(t_cmd *cmd)
{
	int	i;
	int	fd;

	i = 0;
	while (ft_strlen(cmd->file[i]))
	{
		if (cmd->redirect[i] == 2)
			fd = open(cmd->file[i], O_RDWR | O_CREAT \
					| O_TRUNC, S_IRUSR | S_IWUSR);
		else if (cmd->redirect[i] == 3)
			fd = open(cmd->file[i], O_RDWR | O_CREAT \
					| O_APPEND, S_IRUSR | S_IWUSR);
		else
			fd = open(cmd->file[i], O_RDONLY);
		if (fd < 0)
			ft_error(0, strerror(errno), cmd->file[i], errno);
		close(fd);
		i++;
	}
}

void	ft_run_special(t_cmd *cmd, char ***env)
{
	size_t	arg_len;

	arg_len = ft_strlen(cmd->arg[0]);
	if (cmd->redirect[0])
		ft_open_files(cmd);
	if (!ft_strncmp(cmd->arg[0], "/cd", 3) && arg_len == 3)
		ft_cd(cmd->arg, env, 0);
	if (!ft_strncmp(cmd->arg[0], "/export", 7)
		&& cmd->arg[1] && arg_len == 7)
		ft_export(cmd->arg, env, 0);
	if (!ft_strncmp(cmd->arg[0], "/unset", 6) && arg_len == 6)
		ft_unset(cmd->arg, env, 0);
	if (!ft_strncmp(cmd->arg[0], "/exit", arg_len) && arg_len == 5)
		ft_exit(cmd->arg);
}
