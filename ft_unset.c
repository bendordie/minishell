/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 22:37:05 by cshells           #+#    #+#             */
/*   Updated: 2021/06/06 17:47:58 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_unset_identifier_validation(char *arg)
{
	int	i;

	i = 0;
	if ((arg[i] < '0' || arg[i] > '9')
		&& (arg[i] < 'A' || arg[i] > 'Z')
		&& (arg[i] < 'a' || arg[i] > 'z'))
	{
		printf("minibender!: '%s': not a valid identifier\n", arg);
		return (1);
	}
	while (arg[i])
	{
		if ((arg[i] < '0' || arg[i] > '9')
			&& (arg[i] < 'A' || arg[i] > 'Z')
			&& (arg[i] < 'a' || arg[i] > 'z'))
		{
			printf("minibender!: '%s': not a valid identifier\n", arg);
			return (1);
		}
		i++;
	}
	return (0);
}

char	**ft_rebuild_env(char **env, int i)
{
	int		j;
	t_list	*begin;
	t_list	*list;
	t_list	*tmp;

	j = 0;
	list = ft_array_to_list(env);
	begin = list;
	while (j < i)
	{
		if (i == j + 1)
			tmp = list;
		list = list->next;
		j++;
	}
	tmp->next = list->next;
	free(list);
	return (ft_list_to_array(&begin, -1));
}

void	ft_remove_env_value(int i, char **arg, char ***env)
{
	int		j;
	char	**tmp;

	j = ft_find_env_key(arg[i], *env, ft_strlen(arg[i]));
	if (j >= 0)
	{
		tmp = *env;
		*env = ft_rebuild_env(*env, j);
		ft_free_double_array(tmp);
	}
}

void	ft_unset(char **arg, char ***env, int fork)
{
	int		i;
	int		j;
	char	**tmp;

	i = 1;
	if (arg[1])
	{
		while (arg[i])
		{
			if (ft_unset_identifier_validation(arg[i]))
			{
				i++;
				continue ;
			}
			else
				ft_remove_env_value(i, arg, env);
			i++;
		}
	}
	if (fork)
		exit(0);
}
