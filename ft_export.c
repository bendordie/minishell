/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 02:11:05 by cshells           #+#    #+#             */
/*   Updated: 2021/06/06 18:13:01 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_export_editor(char **arg, char ***env)
{
	int		i;
	int		key;
	char	**tmp;

	i = 1;
	while (arg[i])
	{
		key = ft_export_identifier_validation(arg[i]);
		if (key == 1)
		{
			i++;
			continue ;
		}
		else
		{
			tmp = *env;
			*env = ft_edit_env(arg[i], *env, key);
			ft_free_double_array(tmp);
		}
		i++;
	}
}

void	ft_export(char **arg, char ***env, int fork)
{
	if (arg[1])
		ft_export_editor(arg, env);
	ft_sort_array(*env);
	if (!arg[1])
		ft_export_output(*env);
	if (fork)
		exit(0);
}
