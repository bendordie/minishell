/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <cshells@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:40:04 by cshells           #+#    #+#             */
/*   Updated: 2020/11/04 19:36:40 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;
	size_t	i;

	i = 0;
	count = count * size;
	dest = (void*)malloc(count * size);
	if (!dest)
		return (0);
	while (i < count)
	{
		*(char*)(dest + i) = '\0';
		i++;
	}
	return ((void*)dest);
}
