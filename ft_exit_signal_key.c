/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_signal_key.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:29:47 by cshells           #+#    #+#             */
/*   Updated: 2021/06/06 17:03:27 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_exit_signal_key(t_all *all)
{
	if (!ft_strcmp(all->str, "\4"))
	{
		all->str[0] = 0;
		if (ft_strlen(all->ready) > 0)
			return ;
		tcsetattr(0, TCSANOW, all->term_n);
		write(1, "exit\n", 5);
		exit(0);
	}
}
