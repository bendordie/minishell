/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_env_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 22:55:03 by cshells           #+#    #+#             */
/*   Updated: 2021/05/30 19:19:20 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_find_env_key(char *arg, char **env, int equal_pos)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(arg, env[i], equal_pos))
			return (i);
		i++;
	}
	return (-1);
}
