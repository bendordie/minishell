/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edit_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:55:53 by cshells           #+#    #+#             */
/*   Updated: 2021/06/07 17:06:27 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**ft_add_env_line(char *arg, char **env, int append)
{
	int		k;
	char	*tmp;
	char	*tmp2;
	t_list	*list;
	t_list	*new;

	if (append == 2)
	{
		k = ft_strlen_to_char(arg, '+');
		tmp = ft_substr(arg, 0, k);
		tmp2 = ft_strjoin(tmp, ft_strchr(arg, '='));
		free(tmp);
		new = ft_lstnew(tmp2);
		list = ft_array_to_list(env);
		ft_lstadd_back(&list, new);
		return (ft_list_to_array(&list, ft_lstsize(list) - 1));
	}
	else
	{
		new = ft_lstnew(arg);
		list = ft_array_to_list(env);
		ft_lstadd_back(&list, new);
		return (ft_list_to_array(&list, -1));
	}
}

char	**ft_edit_env_line(char *arg, char **env, int i)
{
	int		n;
	t_list	*new;
	t_list	*list;

	n = 0;
	list = ft_array_to_list(env);
	new = list;
	while (n < i)
	{
		new = new->next;
		n++;
	}
	new->content = ft_strdup(arg);
	return (ft_list_to_array(&list, i));
}

char	**ft_append_env_line(char *arg, char **env, int i)
{
	int		n;
	t_list	*new;
	t_list	*list;

	n = 0;
	list = ft_array_to_list(env);
	new = list;
	while (n < i)
	{
		new = new->next;
		n++;
	}
	new->content = ft_strjoin(new->content, ft_strchr(arg, '=') + 1);
	return (ft_list_to_array(&list, i));
}

char	**ft_reallocate_env(char **env)
{
	int		i;
	int		size;
	char	**dest;

	i = 0;
	size = 0;
	while (env[i])
	{
		i++;
		size++;
	}
	dest = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (env[i])
	{
		dest[i] = ft_strdup(env[i]);
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	**ft_edit_env(char *arg, char **env, int append)
{
	int	i;
	int	k;

	k = ft_env_key_length(arg);
	i = ft_find_env_key(arg, env, k);
	if (!ft_strchr(arg, '=') && i > 0)
		return (ft_reallocate_env(env));
	if (i > 0)
	{
		if (append == 0)
			return (ft_edit_env_line(arg, env, i));
		else
			return (ft_append_env_line(arg, env, i));
	}
	else
		return (ft_add_env_line(arg, env, append));
}
