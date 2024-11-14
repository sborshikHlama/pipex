/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:18:23 by aevstign          #+#    #+#             */
/*   Updated: 2023/12/29 18:43:28 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <bits/waitflags.h>

void	exec(char *cmd, char **env)
{
	char	**splited_cmd;
	char	*path;

	splited_cmd = ft_split(cmd, ' ');
	path = ft_get_path(splited_cmd[0], env);
	if (execve(path, splited_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(splited_cmd[0], 2);
		ft_free_tab(splited_cmd);
		exit(0);
	}
}

void	child(char **argv, int *p_fd, char **env)
{
	int	fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		exit(0);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	exec(argv[2], env);
}

void	parent(char **argv, int *p_fd, char **env, pid_t pid)
{
	int	fd;
	int	status;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit(0);
	waitpid(pid, &status, WNOHANG);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	exec(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (argc != 5)
		exit_handler(3);
	if (pipe(p_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (!pid)
		child(argv, p_fd, env);
	parent(argv, p_fd, env, pid);
}
