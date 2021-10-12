/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar_question.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:23:55 by cshells           #+#    #+#             */
/*   Updated: 2021/06/06 16:53:33 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_dollar_question(void)
{
	if (g_global_error > 255 && g_global_error != 65280)
		g_global_error = g_global_error % 255;
	if (g_global_error == 65280)
		g_global_error = 255;
	while (g_global_error < 0)
		g_global_error = 256 + g_global_error;
	ft_putstr_fd("minibender!: ", 2);
	ft_putnbr_fd(g_global_error, 2);
	ft_putendl_fd(": command not found", 2);
	exit(127);
}
