/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:02:02 by jhapke            #+#    #+#             */
/*   Updated: 2025/03/19 12:24:20 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
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
		ft_error_handler(4, cmd);
		free(cmd_path);
		ft_free(cmd_arg);
		exit(126);
	}
}

void	ft_process(int fds[2], char *argv, char **env)
{
	pid_t	pid;

	if (pipe(fds) == -1)
		ft_error_handler(2, "pipe failed");
	pid = fork();
	if (pid == -1)
		ft_error_handler(3, "fork failed");
	if (pid == 0)
	{
		dup2(fds[1], STDOUT_FILENO);
		close(fds[0]);
		ft_execution(argv, env);
		exit(0);
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	ft_filemanager(int argc, char **argv, int i)
{
	int	infile;
	int	outfile;

	if (i < argc - 1)
	{
		infile = open(argv[1], O_RDONLY);
		if (infile == -1)
		{
			ft_error_handler(1, argv[1]);
			exit(1);
		}
		dup2(infile, STDIN_FILENO);
		close(infile);
	}
	else
	{
		outfile = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile == -1)
		{
			ft_error_handler(1, argv[i]);
			exit(1);
		}
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
	}
}

void	ft_here_doc(char **argv)
{
	int		here_doc_fds[2];
	char	*line;
	size_t	len;

	if (pipe(here_doc_fds) == -1)
		ft_error_handler(2, "pipe failed");
	while (1)
	{
		line = ft_get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		len = (ft_strlen(line));
		while (line[len - 1] == '\n' || line[len - 1]  == '\0')
			line[--len] = '\0';
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
		{
			free (line);
			break ;
		}
		write(here_doc_fds[1], line, ft_strlen(line));
		free (line);
	}
	close(here_doc_fds[1]);
	dup2(here_doc_fds[0], STDIN_FILENO);
	close(here_doc_fds[0]);
}

int	main(int argc, char **argv, char **env)
{
	int	fds[2];
	int	i;

	if (argc >= 6 && ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 3;
		ft_here_doc(argv);
	}
	else if (argc >= 5 && ft_strncmp(argv[1], "here_doc", 8) != 0)
	{
		i = 2;
		ft_filemanager(argc, argv, i);
	}
	else
	{
		write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40);
		exit(1);
	}
	while (i++ < argc - 2)
		ft_process(fds, argv[i], env);
	ft_filemanager(argc, argv, argc - 1);
	ft_execution(argv[argc - 2], env);
	return (0);
}
