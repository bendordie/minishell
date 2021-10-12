/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 21:32:07 by cshells           #+#    #+#             */
/*   Updated: 2021/05/30 19:41:38 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_sort_array(char **array)
{
	int		i;
	char	*buf;

	i = 1;
	while (array[i])
	{
		if (ft_strncmp(array[i - 1], array[i], 999) > 0)
		{
			buf = array[i - 1];
			array[i - 1] = array[i];
			array[i] = buf;
			i = 0;
		}
		i++;
	}
}
