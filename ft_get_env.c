/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:09:55 by cshells           #+#    #+#             */
/*   Updated: 2021/05/30 19:20:02 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_get_env(char *key, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(key, env[i], ft_strlen(key)))
			return (ft_strchr(env[i], '=') + 1);
		i++;
	}
	return (0);
}
