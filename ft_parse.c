/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onightst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:12:48 by onightst          #+#    #+#             */
/*   Updated: 2021/06/07 17:57:14 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_slash_cycle(t_all *all, int sc)
{
	int		i;
	char	*temp;

	i = 0;
	while (all->cm[i]->on == 1)
	{
		if (ft_strlen(all->cm[i]->arg[0]) > 0)
		{
			temp = all->cm[i]->arg[0];
			all->cm[i]->arg[0] = ft_strjoin("/", all->cm[i]->arg[0]);
			free(temp);
		}
		i++;
	}
}

void	ft_alone_dollar(t_all *all, char *line, char **env)
{
	all->cm[all->sc]->on = 1;
	all->cm[all->sc + 1]->on = 0;
	all->enn = -1;
	all->itf = all->pi;
	all->enn = ft_dollar(line, all->itf, env);
	all->w = 0;
	if (all->enn >= 0)
	{
		while (env[all->enn][all->w] != '=')
			all->w++;
		all->pi += all->w + 1;
		all->w++;
		while (env[all->enn][all->w])
		{
			all->cm[all->sc]->arg[all->ac][all->count] = env[all->enn][all->w];
			all->count++;
			all->w++;
		}
	}
	else
		ft_alone_dollar_else(all, line);
}

void	ft_ordinary(t_all *all, char *line)
{
	all->cm[all->sc]->on = 1;
	all->cm[all->sc + 1]->on = 0;
	all->cm[all->sc]->arg[all->ac][all->count] = line[all->pi];
	all->count++;
	all->pi++;
}

void	ft_parse_cycle(t_all *all, char *line, char **env)
{
	while (line[all->pi])
	{
		if (line[all->pi] == '\\' && line[all->pi + 1] == '\\')
			ft_slashes(all, line);
		else if (line[all->pi] == '\\')
			ft_one_slashe(all, line);
		else if (line[all->pi] == '\'')
			ft_solo_quote(all, line);
		else if (line[all->pi] == '\"')
			ft_double_quote(all, line, all->ee);
		else if (line[all->pi] == ' ')
			ft_space(all, line);
		else if (line[all->pi] == ';')
			ft_separator(all, line);
		else if (line[all->pi] == '|')
			ft_poip(all, line);
		else if (line[all->pi] == '$')
			ft_alone_dollar(all, line, all->ee);
		else
			ft_ordinary(all, line);
	}
}

void	ft_parse(char *line, t_all *all, char **env)
{
	ft_make_struct(line, env, all);
	ft_cal_nums(all);
	all->cm[0]->on = 0;
	ft_parse_cycle(all, line, env);
	ft_redirections(all, all->sc);
	ft_slash_cycle(all, all->sc);
	ft_cut_ends(all);
	ft_check_redir0(all);
}
