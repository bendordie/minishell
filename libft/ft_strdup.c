/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <cshells@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:08:29 by cshells           #+#    #+#             */
/*   Updated: 2020/11/04 19:41:47 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*dest;
	size_t		i;
	size_t		length;

	i = 0;
	length = ft_strlen(s1);
	dest = (char*)ft_calloc(length + 1, sizeof(char));
	if (!dest)
		return (0);
	while (i < length)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
