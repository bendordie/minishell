/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <cshells@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:57:13 by cshells           #+#    #+#             */
/*   Updated: 2020/11/04 19:42:01 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	size;
	size_t	i;

	i = 0;
	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		dest = (char*)ft_calloc(size + 1, sizeof(char));
		if (!dest)
			return (0);
		while (*s1 != '\0')
			dest[i++] = *(s1++);
		while (*s2 != '\0')
			dest[i++] = *(s2++);
		dest[i] = '\0';
		return (dest);
	}
	return (0);
}
