/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 21:00:24 by cshells           #+#    #+#             */
/*   Updated: 2021/06/06 17:37:47 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_run_command(t_cmd *cmd, char **env)
{
	size_t	arg_len;

	arg_len = ft_strlen(cmd->arg[0]);
	if (!ft_strncmp(cmd->arg[0], "/$?", arg_len) && arg_len == 3)
		ft_dollar_question();
	else if (!ft_strncmp(cmd->arg[0], "/echo", arg_len) && arg_len == 5)
		ft_echo(cmd->arg);
	else if (!ft_strncmp(cmd->arg[0], "/cd", arg_len) && arg_len == 3)
		ft_cd(cmd->arg, &env, 1);
	else if (!ft_strncmp(cmd->arg[0], "/pwd", arg_len) && arg_len == 4)
		ft_pwd();
	else if (!ft_strncmp(cmd->arg[0], "/export", arg_len) && arg_len == 7)
		ft_export(cmd->arg, &env, 1);
	else if (!ft_strncmp(cmd->arg[0], "/env", arg_len) && arg_len == 4)
		ft_env(env);
	else if (!ft_strncmp(cmd->arg[0], "/unset", arg_len) && arg_len == 6)
		ft_unset(cmd->arg, &env, 1);
	else
		ft_run_binary(cmd, env);
	return (0);
}
