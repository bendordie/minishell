/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_special.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:13:17 by cshells           #+#    #+#             */
/*   Updated: 2021/06/06 17:15:19 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_is_special(t_cmd *cmd)
{
	size_t	arg_len;

	arg_len = ft_strlen(cmd->arg[0]);
	if (!ft_strncmp(cmd->arg[0], "/cd", 3) && arg_len == 3)
		return (1);
	if (!ft_strncmp(cmd->arg[0], "/export", 7)
		&& cmd->arg[1] && arg_len == 7)
		return (1);
	if (!ft_strncmp(cmd->arg[0], "/unset", 6) && arg_len == 6)
		return (1);
	if (!ft_strncmp(cmd->arg[0], "/exit", arg_len) && arg_len == 5)
		return (1);
	return (0);
}
