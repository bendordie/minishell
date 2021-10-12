/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_increase_shlvl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:31:36 by cshells           #+#    #+#             */
/*   Updated: 2021/06/06 17:14:15 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_is_str_digit(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_set_shlvl_to_1(char ***env, int error, int value)
{
	char	**tmp;

	tmp = ft_split("/export SHLVL=1", ' ');
	ft_export(tmp, env, 0);
	ft_free_double_array(tmp);
	if (error)
	{
		ft_putstr_fd("minibender!: warning: shell level (", 2);
		ft_putnbr_fd(value, 2);
		ft_putendl_fd(") too high, resetting to 1", 2);
	}
}

void	ft_increase_shlvl(char ***env)
{
	int		value;
	char	*str_value;
	char	*result;
	char	**tmp;

	value = ft_atoi(ft_get_env("SHLVL=", *env));
	if (value < 0)
		value = -1;
	if (!ft_is_str_digit(ft_get_env("SHLVL=", *env)))
		ft_set_shlvl_to_1(env, 0, value);
	else if (value > 998)
		ft_set_shlvl_to_1(env, 1, value);
	else
	{
		value++;
		str_value = ft_itoa(value);
		result = ft_strjoin("/export SHLVL=", str_value);
		free(str_value);
		tmp = ft_split(result, ' ');
		free(result);
		ft_export(tmp, env, 0);
		ft_free_double_array(tmp);
	}
}
