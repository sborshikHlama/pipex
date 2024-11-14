/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:02:43 by aevstign          #+#    #+#             */
/*   Updated: 2023/12/28 17:24:25 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_handler(int n_exit)
{
	if (n_exit == 3)
		ft_putstr_fd("Error, bad arguments\n", 2);
	if (n_exit == 1)
		ft_putstr_fd("Error", 2);
	exit(0);
}

void	*ft_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub_str;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub_str = ft_substr(env[i], 0, j);
		if (ft_strncmp(sub_str, name, 4) == 0)
		{
			free(sub_str);
			return (env[i] + j + 1);
		}
		free(sub_str);
		i++;
	}
	return (NULL);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i++])
		free(tab[i]);
	free(tab);
}

char	*ft_get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**all_path;
	char	*part_path;
	char	**splited_cmd;

	i = 0;
	all_path = ft_split(ft_getenv("PATH", env), ':');
	splited_cmd = ft_split(cmd, ' ');
	while (all_path[i++])
	{
		part_path = ft_strjoin(all_path[i], "/");
		exec = ft_strjoin(part_path, splited_cmd[0]);
		free(part_path);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_tab(splited_cmd);
			return (exec);
		}
		free(exec);
	}
	ft_free_tab(all_path);
	ft_free_tab(splited_cmd);
	return (cmd);
}
