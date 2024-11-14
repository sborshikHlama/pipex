/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:04:08 by aevstign          #+#    #+#             */
/*   Updated: 2023/12/28 17:16:38 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../ft_libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>  
# include <stdlib.h>
# include <sys/wait.h>

void	exit_handler(int n_exit);
void	*ft_getenv(char *name, char **env);
void	ft_free_tab(char **tab);
char	*ft_get_path(char *cmd, char **env);
void	exec(char *cmd, char **env);
void	child(char **argv, int *p_fd, char **env);
void	parent(char **argv, int *p_fd, char **env, pid_t pid);

#endif