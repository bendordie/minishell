/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onightst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:56:24 by onightst          #+#    #+#             */
/*   Updated: 2021/06/07 17:15:54 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_solo_quote(t_all *all, char *line)
{
	all->cm[all->sc]->on = 1;
	all->cm[all->sc + 1]->on = 0;
	all->itf = all->pi;
	all->check = ft_check_quotes_s(line, all->itf);
	if (all->check > 0)
	{
		all->pi++;
		while (line[all->pi] != '\'')
		{
			all->cm[all->sc]->arg[all->ac][all->count] = line[all->pi];
			all->count++;
			all->pi++;
			all->check--;
		}
		all->pi++;
	}
	else
	{
		all->cm[all->sc]->arg[all->ac][all->count] = line[all->pi];
		all->count++;
		all->pi++;
	}
}

void	ft_dollar_reac(t_all *all, char *line)
{
	if (line[all->pi + 1] == '?')
		ft_doll_que(all);
	else if (line[all->pi + 1] >= '0' && line[all->pi + 1] <= '9')
		all->pi += 2;
	else
	{
		all->pi++;
		while (line[all->pi] != ';' && line[all->pi] != '|'
			&& line[all->pi] != ' '
			&& line[all->pi] != '$' && line[all->pi] != '('
			&& line[all->pi] != ')' && line[all->pi] != '\"')
			all->pi++;
	}
}

void	ft_count_equal_pi(t_all *all, char *line)
{
	all->cm[all->sc]->arg[all->ac][all->count] = line[all->pi];
	all->count++;
	all->pi++;
}

void	ft_if_dq_dollar(t_all *all, char *line, char **env)
{
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
		ft_dollar_reac(all, line);
}

void	ft_double_quote(t_all *all, char *line, char **env)
{
	all->cm[all->sc]->on = 1;
	all->cm[all->sc + 1]->on = 0;
	all->itf = all->pi;
	all->check = ft_check_quotes_d(line, all->itf);
	if (all->check > 0)
	{
		all->pi++;
		while (line[all->pi] != '\"')
		{
			if (line[all->pi] == '\\' && line[all->pi + 1] == '\\')
				ft_slashes(all, line);
			else if (line[all->pi] == '\\')
				ft_one_slashe(all, line);
			if (line[all->pi] == '$')
				ft_if_dq_dollar(all, line, env);
			else
				ft_count_equal_pi(all, line);
		}
		all->check--;
		all->pi++;
	}
	else
		ft_count_equal_pi(all, line);
}
