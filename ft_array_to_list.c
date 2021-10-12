/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 02:20:43 by cshells           #+#    #+#             */
/*   Updated: 2021/05/30 19:13:47 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_list	*ft_array_to_list(char **array)
{
	int		i;
	t_list	*begin;
	t_list	*current;

	if (!array)
		return (0);
	i = 1;
	begin = ft_lstnew(array[0]);
	current = begin;
	while (array[i])
	{
		current->next = ft_lstnew(array[i]);
		current = current->next;
		i++;
	}
	return (begin);
}
