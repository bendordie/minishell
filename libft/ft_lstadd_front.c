/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <cshells@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:48:18 by cshells           #+#    #+#             */
/*   Updated: 2020/11/06 13:18:01 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && !*lst)
	{
		*lst = new;
		return ;
	}
	if (lst && *lst)
	{
		new->next = *lst;
		*lst = new;
	}
}
