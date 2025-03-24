/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:02:02 by jhapke            #+#    #+#             */
/*   Updated: 2025/03/21 12:05:34 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"
#include "pipex.h"

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

void	ft_process(int fds[2], char **argv, char **env, int i)
{
	pid_t	pid;

	if (pipe(fds) == -1)
		ft_error_handler(2, "pipe failed");
	pid = fork();
	if (pid == -1)
		ft_error_handler(3, "fork failed");
	if (pid == 0)
	{
		if (i == 2)
			ft_infile_manager(argv);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[0]);
		ft_execution(argv[i], env);
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	ft_here_doc(char **argv)
{
	int		here_doc_fds[2];
	char	*line;

	if (pipe(here_doc_fds) == -1)
		ft_error_handler(2, "pipe failed");
	while (1)
	{
		line = ft_get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0
			&& ft_strlen(line) == ft_strlen(argv[2]))
		{
			free (line);
			break ;
		}
		write(here_doc_fds[1], line, ft_strlen(line));
		write(here_doc_fds[1], "\n", 1);
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
	int	here_doc;

	here_doc = 0;
	if (argc >= 6 && ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 3;
		ft_here_doc(argv);
		here_doc = 1;
	}
	else if (argc >= 5)
		i = 2;
	else
	{
		write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40);
		exit(1);
	}
	while (i < argc - 2)
		ft_process(fds, argv, env, i++);
	ft_filemanager(argv, argc - 1, here_doc);
	ft_execution(argv[argc - 2], env);
	return (0);
}
