/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:17:49 by cshells           #+#    #+#             */
/*   Updated: 2021/06/06 16:55:51 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_error(char *program_name, char *err, char *arg, int err_code)
{
	if (program_name)
	{
		ft_putstr_fd("minibender!: ", 2);
		ft_putstr_fd(program_name, 2);
		ft_putstr_fd(": '", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': ", 2);
		ft_putendl_fd(err, 2);
	}
	else
	{
		ft_putstr_fd("minibender!: '", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': ", 2);
		ft_putendl_fd(err, 2);
	}
	exit(err_code);
}
