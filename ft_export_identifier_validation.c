/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_identifier_validation.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:58:20 by cshells           #+#    #+#             */
/*   Updated: 2021/06/06 17:07:09 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_identifier_error(char *arg)
{
	ft_putstr_fd("minibender!: '", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd("': not a valid identifier", 2);
	return (1);
}

int	ft_export_identifier_validation(char *arg)
{
	int	i;

	i = -1;
	if ((arg[0] < 'A' || arg[0] > 'Z') && (arg[0] < 'a' || arg[0] > 'z'))
		return (ft_identifier_error(arg));
	while (arg[++i])
	{
		if ((arg[i] < '0' || arg[i] > '9')
			&& (arg[i] < 'A' || arg[i] > 'Z')
			&& (arg[i] < 'a' || arg[i] > 'z'))
		{
			if (arg[i] == '+')
			{
				if (arg[i + 1] == '=')
					return (2);
				else
					return (ft_identifier_error(arg));
			}
			else if (arg[i] == '=')
				return (0);
			else
				return (ft_identifier_error(arg));
		}
	}
	return (0);
}
