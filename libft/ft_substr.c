/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <cshells@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:46:34 by cshells           #+#    #+#             */
/*   Updated: 2020/11/06 16:52:09 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (0);
	if (!len || (size_t)start >= ft_strlen((char*)s))
		return (ft_strdup(""));
	dest = (char*)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
