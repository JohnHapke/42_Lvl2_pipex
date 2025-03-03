/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:40:46 by jhapke            #+#    #+#             */
/*   Updated: 2025/02/21 09:28:49 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

void	ft_error_handler(int i, char *argv)
{
	if (i == 1)
		printf("./pipex: %s: No such file or directory\n", argv);
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
		ft_putstr_fd("./pipex: ", 2);
		ft_putstr_fd(argv, 2);
		ft_putstr_fd(": command does not exist\n", 2);
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
