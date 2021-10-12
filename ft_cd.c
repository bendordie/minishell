/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 00:28:27 by cshells           #+#    #+#             */
/*   Updated: 2021/06/06 16:50:28 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_cd_error(char *arg, char *err)
{
	ft_putstr_fd("minibender!: cd: '", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': ", 2);
	ft_putendl_fd(err, 2);
}

void	ft_cd(char **arg, char ***env, int fork)
{
	int		ret;
	char	*oldpwd;

	if (!ft_get_env("HOME=", *env))
	{
		ft_putendl_fd("minibender!: cd: HOME not set", 2);
		return ;
	}
	oldpwd = ft_strdup(ft_get_env("PWD=", *env));
	if (!arg[1])
		ret = chdir(ft_get_env("HOME=", *env));
	else
		ret = chdir(arg[1]);
	if (ret)
		ft_cd_error(arg[1], strerror(errno));
	else
	{
		ft_pwd_update(env);
		ft_oldpwd_update(oldpwd, env);
	}
	if (fork)
		exit(0);
}
