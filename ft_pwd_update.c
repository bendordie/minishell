/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:40:56 by cshells           #+#    #+#             */
/*   Updated: 2021/06/07 17:13:00 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_pwd_update(char ***env)
{
	char	*tmp;
	char	*path;
	t_all	all_local;

	path = (char *)ft_calloc(sizeof(char), 1000);
	if (getcwd(path, 1000))
	{
		tmp = ft_strjoin("\"", path);
		free(path);
		path = ft_strjoin(tmp, "\"");
		free(tmp);
		tmp = path;
		path = ft_strjoin("export PWD=", path);
		free(tmp);
		ft_parse(path, &all_local, *env);
		free(path);
		ft_export(all_local.cm[0]->arg, env, 0);
		ft_bzero_struct(&all_local);
	}
}
