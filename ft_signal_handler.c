/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:11:15 by cshells           #+#    #+#             */
/*   Updated: 2021/06/06 17:42:55 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_signal_handler(int status)
{
	if (WIFSIGNALED(status))
	{
		if (status == SIGINT)
		{
			write(1, "\n", 1);
			g_global_error = 130;
		}
		else if (status == SIGQUIT)
		{
			write(1, "Quit: 3\n", 8);
			g_global_error = 131;
		}
		else if (status == SIGTERM)
		{
			write(1, "Terminated: 15\n", 15);
			g_global_error = 143;
		}
		else
			g_global_error = status;
	}
	else
		g_global_error = status;
}
