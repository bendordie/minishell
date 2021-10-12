/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:45:07 by cshells           #+#    #+#             */
/*   Updated: 2021/06/06 17:37:11 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_search_file(char *path, char *name)
{
	size_t			len;
	struct dirent	*dp;
	DIR				*dirp;

	dirp = opendir(path);
	if (dirp == NULL)
		return (-1);
	len = ft_strlen(name);
	dp = readdir(dirp);
	while (dp)
	{
		if (dp->d_namlen == len && ft_strcmp(dp->d_name, name) == 0)
		{
			(void) closedir(dirp);
			return (1);
		}
		dp = readdir(dirp);
	}
	(void)closedir(dirp);
	return (0);
}

void	ft_run_local_bin(t_cmd *cmd, char **env)
{
	if (open(&cmd->arg[0][1], O_RDONLY) > 0)
	{
		execve(&cmd->arg[0][1], cmd->arg, env);
		ft_putstr_fd("minibender!: ", 2);
		ft_putendl_fd(strerror(errno), 2);
		exit(errno);
	}
	else
	{
		ft_putstr_fd("minibender!: ", 2);
		ft_putendl_fd(strerror(errno), 2);
		exit(errno);
	}
}

void	ft_run_binary(t_cmd *cmd, char **env)
{
	int		i;
	char	*env_path_str;
	char	*program_path;
	char	**path_variables;

	i = 0;
	if (cmd->arg[0][1] == '.' || cmd->arg[0][1] == '/')
		ft_run_local_bin(cmd, env);
	env_path_str = ft_get_env("PATH", env);
	if (!env_path_str)
		ft_error(0, "No such file or directory", &cmd->arg[0][1], 127);
	path_variables = ft_split(env_path_str, ':');
	while (path_variables[i])
	{
		if (ft_search_file(path_variables[i], &cmd->arg[0][1]) > 0)
		{
			program_path = ft_strjoin(path_variables[i], cmd->arg[0]);
			execve(program_path, cmd->arg, env);
			ft_putstr_fd("minibender!: ", 2);
			ft_putendl_fd(strerror(errno), 2);
			exit(errno);
		}
		i++;
	}
	ft_error(0, "command not found", &cmd->arg[0][1], 127);
}
