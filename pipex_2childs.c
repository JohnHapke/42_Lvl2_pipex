/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_2childs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:39:41 by jhapke            #+#    #+#             */
/*   Updated: 2025/03/19 12:39:35 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

void	ft_closefds(int fds[2])
{
	close(fds[0]);
	close(fds[1]);
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

void	ft_execution(char *cmd, char **env)
{
	char	**cmd_arg;
	char	*cmd_path;

	cmd_arg = ft_split(cmd, ' ');
	if (!cmd_arg || !cmd_arg[0])
	{
		ft_error_handler(4, cmd);
		ft_free(cmd_arg);
		exit(127);
	}
	cmd_path = ft_get_cmd_path(cmd_arg[0], env);
	if (!cmd_path)
	{
		ft_error_handler(4, cmd);
		ft_free(cmd_arg);
		exit(127);
	}
	if (execve(cmd_path, cmd_arg, env) == -1)
	{
		perror("execve failed");
		ft_error_handler(4, cmd);
		free(cmd_path);
		ft_free(cmd_arg);
		exit(126);
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

void	ft_child1(int fds[2], char **argv, char **env)
{
	int		outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		ft_error_handler(1, argv[4]);
	else
	{
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
	}
	dup2(fds[0], STDIN_FILENO);
	ft_closefds(fds);
	ft_execution(argv[3], env);
}

void	ft_child(int fds[2], char **argv, char **env)
{
	int		infile;
	char	*cmd_path;
	char	buffer[100];
	char	**cmd_arg;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		ft_error_handler(1, argv[1]);
	else
	{
		dup2(infile, STDIN_FILENO);
		close(infile);
	}
	dup2(fds[1], STDOUT_FILENO);
	ft_closefds(fds);
	cmd_arg = ft_split(argv[2], ' ');
	cmd_path = ft_get_cmd_path(cmd_arg[0], env);
	if (!cmd_path)
		ft_pass_input(buffer, sizeof(buffer));
	free (cmd_path);
	ft_free(cmd_arg);
	ft_execution(argv[2], env);
}

void	ft_pass_input(char *buffer, ssize_t size)
{
	ssize_t	byte;

	byte = read(STDIN_FILENO, buffer, size);
	while (byte > 0)
	{
		write(STDOUT_FILENO, buffer, byte);
		byte = read(STDIN_FILENO, buffer, size);
	}
}

int	main(int argc, char **argv, char **env)
{
	int		fds[2];
	pid_t	pid;
	pid_t	pid1;

	if (argc != 5)
	{
		write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40);
		exit(1);
	}
	if (pipe(fds) == -1)
		ft_error_handler(2, "pipe failed");
	pid = fork();
	if (pid == -1)
		ft_error_handler(3, "fork failed");
	if (pid == 0)
		ft_child(fds, argv, env);
	pid1 = fork();
	if (pid1 == -1)
		ft_error_handler(3, "fork failed");
	if (pid1 == 0)
		ft_child1(fds, argv, env);
	ft_closefds(fds);
	waitpid(pid, NULL, 0);
	waitpid(pid1, NULL, 0);
	return (0);
}
