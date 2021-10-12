/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onightst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:01:28 by onightst          #+#    #+#             */
/*   Updated: 2021/06/07 17:59:16 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_dolce(char *line, int i, char **env, char **check)
{
	int	j;

	j = 0;
	*check = ft_calloc(1000, sizeof(char));
	i++;
	while (line[i] != ' ' && line[i] != 0 && line[i] != '\"')
	{
		(*check)[j] = line[i];
		j++;
		i++;
	}
	(*check)[j] = '\0';
}

int	ft_dollar_while(char **env, char *check, int c, int j)
{
	int	i;

	i = 0;
	while (env[i][j] != '=')
	{
		if (env[i][j] == check[c])
		{
			j++;
			c++;
		}
		else
		{
			i++;
			j = 0;
			c = 0;
		}
		if (env[i] == 0)
			return (-1);
	}
	return (i);
}

int	ft_dollar(char *line, int i, char **env)
{
	char	*check;
	int		j;
	int		c;

	ft_dolce(line, i, env, &check);
	c = 0;
	j = 0;
	i = ft_dollar_while(env, check, c, j);
	free(check);
	return (i);
}

int	ft_check_quotes_s(char *line, int i)
{
	int	letters;

	letters = 0;
	i++;
	while (line[i] != 0)
	{
		if (line[i] == '\'')
			return (letters);
		letters++;
		i++;
	}
	return (0);
}

int	ft_check_quotes_d(char *line, int i)
{
	int	letters;

	letters = 0;
	i++;
	while (line[i] != 0)
	{
		if (line[i] == '\"')
			return (letters);
		letters++;
		i++;
	}
	return (0);
}
