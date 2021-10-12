/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <cshells@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:17:03 by cshells           #+#    #+#             */
/*   Updated: 2020/11/04 19:37:39 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_value(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*dst;

	i = check_value(n);
	if (n == -2147483648)
	{
		dst = ft_strdup("-2147483648");
		return (dst);
	}
	if (!(dst = (char*)ft_calloc((i + 1), sizeof(char))))
		return (0);
	if (n == 0)
		dst[0] = '0';
	if (n < 0)
	{
		n *= -1;
		dst[0] = '-';
	}
	while (n != 0)
	{
		dst[--i] = (n % 10) + '0';
		n = n / 10;
	}
	return (dst);
}
