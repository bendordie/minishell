/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <cshells@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:58:04 by cshells           #+#    #+#             */
/*   Updated: 2020/11/06 14:27:40 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_c(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static int		count_parts(char const *s, char c)
{
	int		part;
	size_t	i;

	i = 0;
	part = 1;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] != '\0')
				part++;
		}
		else
			i++;
	}
	return (part);
}

static void		free_array(char **dest, size_t i)
{
	while (i >= 0)
	{
		free(dest[i]);
		i--;
	}
	free(dest);
}

static char		**write_parts(char **dest, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len;

	i = -1;
	k = 0;
	while (s[k] != '\0')
	{
		while (s[k] == c)
			k++;
		if (s[k] == '\0')
			return (dest);
		j = 0;
		len = ft_strlen_c(&s[k], c);
		dest[++i] = (char*)ft_calloc((size_t)(len + 1), sizeof(char));
		if (!dest[i])
		{
			free_array(dest, i - 1);
			return (0);
		}
		while (j < len)
			dest[i][j++] = s[k++];
	}
	return (dest);
}

char			**ft_split(char const *s, char c)
{
	char		**dest;

	if (!s)
		return (0);
	dest = (char**)ft_calloc((size_t)(count_parts(s, c) + 1), sizeof(char*));
	if (!dest)
		return (0);
	dest = write_parts(dest, s, c);
	return (dest);
}
