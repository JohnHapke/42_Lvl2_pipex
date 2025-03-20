/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:45:48 by jhapke            #+#    #+#             */
/*   Updated: 2025/03/20 09:14:23 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*ft_get_cmd_path(char *cmd, char **env);
char	*ft_get_next_line(int fd_input);
char	**ft_getenv(char **env);
void	ft_error_handler(int i, char *argv);
void	ft_execution(char *cmd, char **env);
void	ft_free(char **path);
void	ft_filemanager(int argc, char **argv, int i, int here_doc);
void	ft_here_doc(char **argv);
void	ft_process(int fds[2], char *argv, char **env);

#endif