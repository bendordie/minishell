/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:29:49 by cshells           #+#    #+#             */
/*   Updated: 2021/06/07 17:07:26 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_if_arg_isalpha(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_isalpha(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_exit(char **arg)
{
	int	status;

	status = 0;
	if (arg[1])
	{
		if (ft_if_arg_isalpha(arg[1]))
			ft_error(0, "numeric argument required\nexit", arg[1], 255);
		if (arg[2])
		{
			ft_putendl_fd("minibender!: exit: too many arguments", 2);
			return ;
		}
		status = ft_atoi(arg[1]);
	}
	write(1, "exit\n", 5);
	exit(status);
}
