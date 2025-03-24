/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:40:04 by jhapke            #+#    #+#             */
/*   Updated: 2025/03/21 08:48:49 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

void	ft_execution(char *cmd, char **env)
{
	char	*cmd_path;
	char	**cmd_arg;

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
		perror("./pipex");
		free(cmd_path);
		ft_free(cmd_arg);
		exit(126);
	}
}

void	ft_parent(int fds[2], char **argv, char **env)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		ft_error_handler(1, argv[4]);
		exit(1);
	}
	dup2(fds[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(fds[0]);
	close(fds[1]);
	ft_execution(argv[3], env);
}

void	ft_child(int fds[2], char **argv, char **env)
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
	dup2(fds[1], STDOUT_FILENO);
	close(fds[0]);
	close(fds[1]);
	ft_execution(argv[2], env);
}

int	main(int argc, char **argv, char **env)
{
	int		fds[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fds) == -1)
			ft_error_handler(2, argv[1]);
		pid = fork();
		if (pid == -1)
			ft_error_handler(3, argv[1]);
		if (pid == 0)
			ft_child(fds, argv, env);
		waitpid(pid, NULL, 0);
		ft_parent(fds, argv, env);
	}
	else
	{
		write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40);
		exit(1);
	}
	return (0);
}
