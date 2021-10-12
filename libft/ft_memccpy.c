/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <cshells@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:51:17 by cshells           #+#    #+#             */
/*   Updated: 2020/11/03 20:28:04 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (dst || src)
	{
		while (i < n)
		{
			*(char*)dst = *(const char*)src;
			if (*(unsigned char*)src == (unsigned char)c)
				return (dst + 1);
			dst++;
			src++;
			i++;
		}
	}
	return (0);
}
