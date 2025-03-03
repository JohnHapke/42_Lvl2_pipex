/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:43:17 by jhapke            #+#    #+#             */
/*   Updated: 2025/02/20 10:46:14 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/wait.h>

void	ft_execution(char *cmd, char **env);
char	**ft_getenv(char **env);
char	*ft_get_cmd_path(char *cmd, char **env);
void	ft_child(int fds[2], char **argv, char **env);
void	ft_error_handler(int i, char *argv);
void	ft_free(char **path);
void	ft_parent(int fds[2], char **argv, char **env);

#endif