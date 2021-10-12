/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 02:20:36 by cshells           #+#    #+#             */
/*   Updated: 2021/06/06 17:16:05 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**ft_list_to_array(t_list **begin_list, int num)
{
	int		i;
	int		size;
	char	**dest;
	t_list	*tmp;
	t_list	*current;

	if (!begin_list || !(*begin_list))
		return (0);
	i = 0;
	current = *begin_list;
	size = ft_lstsize(current);
	dest = (char **)malloc(sizeof(char *) * (size + 1));
	while (current)
	{
		dest[i] = ft_strdup((char *)(current->content));
		if (i == num)
			free(current->content);
		tmp = current;
		current = current->next;
		free(tmp);
		i++;
	}
	dest[i] = 0;
	return (dest);
}
