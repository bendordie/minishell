/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <cshells@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:59:30 by cshells           #+#    #+#             */
/*   Updated: 2020/11/06 13:17:47 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (lst && !*lst)
	{
		*lst = new;
		return ;
	}
	if (lst && *lst)
	{
		node = *lst;
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
}
