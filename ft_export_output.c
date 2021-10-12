/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:52:47 by cshells           #+#    #+#             */
/*   Updated: 2021/06/06 18:14:57 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_export_output(char **env)
{
	int	i;
	int	j;
	int	quote;

	i = 1;
	while (env[i])
	{
		quote = 0;
		j = 0;
		ft_putstr_fd("declare -x ", 1);
		while (env[i][j])
		{
			ft_putchar_fd(env[i][j], 1);
			if (env[i][j] == '=' && !quote)
			{
				ft_putchar_fd('"', 1);
				quote = 1;
			}
			j++;
		}
		if (quote)
			ft_putchar_fd('"', 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}
