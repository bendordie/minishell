/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <cshells@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:53:31 by cshells           #+#    #+#             */
/*   Updated: 2020/11/03 20:24:06 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst || src)
	{
		if (dst < src)
			while (i < len)
			{
				*(char*)(dst + i) = *(char*)(src + i);
				i++;
			}
		else
			while (len--)
				*(char*)(dst + len) = *(char*)(src + len);
	}
	return (dst);
}
