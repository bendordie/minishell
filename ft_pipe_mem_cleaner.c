/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_mem_cleaner.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:32:13 by cshells           #+#    #+#             */
/*   Updated: 2021/06/07 18:45:13 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_pipe_mem_cleaner(pid_t *pid_arr, int **fd_arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(fd_arr[i]);
		i++;
	}
	free(pid_arr);
	free(fd_arr);
}
