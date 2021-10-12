/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oldpwd_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:02:50 by cshells           #+#    #+#             */
/*   Updated: 2021/06/07 17:10:12 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_oldpwd_update(char *oldpwd, char ***env)
{
	char	*tmp;
	t_all	all_local;

	if (oldpwd)
	{
		tmp = ft_strjoin("\"", oldpwd);
		free(oldpwd);
		oldpwd = ft_strjoin(tmp, "\"");
		free(tmp);
		tmp = oldpwd;
		oldpwd = ft_strjoin("export OLDPWD=", oldpwd);
		free(tmp);
		ft_parse(oldpwd, &all_local, *env);
		free(oldpwd);
		ft_export(all_local.cm[0]->arg, env, 0);
		ft_bzero_struct(&all_local);
	}
}
