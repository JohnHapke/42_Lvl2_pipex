/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:49:22 by jhapke            #+#    #+#             */
/*   Updated: 2025/03/21 12:00:34 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"
#include "pipex.h"

char	*ft_get_next_line(int fd_input)
{
	char	*str;
	char	buffer[BUFFER_SIZE + 1];
	int		read_file;
	int		i;

	i = 0;
	if (fd_input < 0 || BUFFER_SIZE < 0)
	{
		str = NULL;
		return (str);
	}
	read_file = read(fd_input, buffer, BUFFER_SIZE);
	if (read_file <= 0)
		return (NULL);
	buffer[read_file] = '\0';
	while (buffer[i] != '\n')
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, buffer, i + 1);
	return (str);
}

void	ft_infile_manager(char **argv)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		ft_error_handler(1, argv[1]);
		exit(1);
	}
	dup2(infile, STDIN_FILENO);
	close(infile);
}

void	ft_filemanager(char **argv, int i, int here_doc)
{
	int	file;

	if (here_doc == 0)
		file = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		file = open(argv[i], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (file == -1)
	{
		ft_error_handler(1, argv[i]);
		exit(1);
	}
	dup2(file, STDOUT_FILENO);
	close(file);
}
