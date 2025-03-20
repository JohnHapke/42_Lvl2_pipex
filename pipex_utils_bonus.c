/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:49:22 by jhapke            #+#    #+#             */
/*   Updated: 2025/03/20 11:15:06 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"

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

void	ft_error_handler(int i, char *argv)
{
	if (i == 1)
	{
		ft_putstr_fd("./pipex: ", 2);
		ft_putstr_fd(argv, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		write(2, "\n", 1);
		exit(1);
	}
	else if (i == 2)
	{
		perror("pipe");
		exit(1);
	}
	else if (i == 3)
	{
		perror("fork");
		exit(1);
	}
	else if (i == 4)
	{
		ft_putstr_fd("./pipex: command not found: ", 2);
		ft_putstr_fd(argv, 2);
		write(2, "\n", 1);
	}
}

void	ft_free(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
}

char	**ft_getenv(char **env)
{
	char	**path;
	int		i;

	path = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_split(env[i] + 5, ':');
			break ;
		}
		i++;
	}
	return (path);
}

char	*ft_get_cmd_path(char *cmd, char **env)
{
	char	**path;
	int		i;
	char	*sub_path;
	char	*cmd_path;

	path = ft_getenv(env);
	if (!path)
		return (NULL);
	i = 0;
	while (path[i])
	{
		sub_path = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(sub_path, cmd);
		free(sub_path);
		if (access(cmd_path, F_OK) == 0)
		{
			ft_free(path);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	ft_free(path);
	return (NULL);
}
