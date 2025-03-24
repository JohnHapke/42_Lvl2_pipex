/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:45:48 by jhapke            #+#    #+#             */
/*   Updated: 2025/03/21 12:00:58 by jhapke           ###   ########.fr       */
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
#  define BUFFER_SIZE 1000
# endif

char	*ft_get_next_line(int fd_input);
void	ft_filemanager(char **argv, int i, int here_doc);
void	ft_here_doc(char **argv);
void	ft_infile_handler(char **argv, int here_doc);
void	ft_process(int fds[2], char **argv, char **env, int i);
void	ft_infile_manager(char **argv);

#endif