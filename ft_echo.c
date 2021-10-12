/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 22:09:13 by cshells           #+#    #+#             */
/*   Updated: 2021/05/30 19:18:42 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_is_flag(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-' || !str[1])
		return (0);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	ft_output(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		ft_putstr_fd(arg[i], 1);
		if (arg[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
}

void	ft_echo(char **arg)
{
	int	i;

	if (!arg[1])
		ft_putchar_fd('\n', 1);
	else if (ft_is_flag(arg[1]))
	{
		i = 2;
		while (ft_is_flag(arg[i]))
			i++;
		ft_output(&arg[i]);
	}
	else
	{
		i = 1;
		ft_output(&arg[i]);
		ft_putchar_fd('\n', 1);
	}
	exit(0);
}
