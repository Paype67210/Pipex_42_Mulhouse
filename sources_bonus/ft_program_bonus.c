/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:11:36 by pdeson            #+#    #+#             */
/*   Updated: 2024/02/26 12:28:12 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"
#include "../headers/libft.h"

void	ft_outfile(t_pipex pipex)
{
	char	buffer[1];
	int		index;

	index = 1;
	while (index > 0)
	{
		index = read(pipex.fd_main, buffer, 1);
		if (index < 0)
			ft_exit("pipex ERROR : Outfile read failed");
		if (index == 0)
			break ;
		if (write(pipex.fd_out, buffer, 1) == -1)
			ft_exit("pipex ERROR : Outfile write error");
	}
	close (pipex.fd_main);
	close (pipex.fd_out);
}

int	ft_loop(t_pipex pipex, int i)
{
	pid_t	pid;
	char	**flag;
	int		pipe_fd[2];
	char	*cmd;

	if (pipe(pipe_fd) == -1)
		ft_exit("pipex ERROR : Loop pipe failed");
	pid = fork();
	if (pid == -1)
		ft_exit("pipex ERROR : Loop fork failed");
	else if (pid == 0)
	{
		close (pipe_fd[0]);
		ft_double_dup(pipex.fd_main, pipe_fd[1]);
		cmd = ft_get_cmd(pipex, i);
		if (!cmd || access(cmd, X_OK) == -1)
			ft_exit("pipex ERROR : Command permission denied");
		flag = ft_split_args_cmd(pipex.argv[i]);
		if (execve(cmd, flag, pipex.envp) == -1)
			ft_exit("pipex ERROR : Execve failed");
	}
	close (pipex.fd_main);
	close (pipe_fd[1]);
	return (pipe_fd[0]);
}

int	ft_heredoc(t_pipex *pipex)
{
	char	*line;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		ft_exit("pipex ERROR : Here_doc pipe failed");
	line = NULL;
	while (1)
	{
		ft_putstr_fd("Here_doc> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line || (ft_strlen(pipex->argv[2]) == ft_strlen(line) - 1 \
			&& !ft_strncmp(line, pipex->argv[2], ft_strlen(pipex->argv[2]))))
			break ;
		if (write(pipe_fd[1], line, ft_strlen(line)) == -1)
			ft_exit("pipex ERROR : Here_doc write failed");
		free (line);
	}
	free (line);
	close (pipe_fd[1]);
	return (pipe_fd[0]);
}

int	ft_infile(t_pipex *pipex)
{
	int		fd;
	int		pipe_fd[2];
	int		index;
	char	buffer[1];

	fd = open(pipex->argv[1], O_RDONLY);
	if (pipe(pipe_fd) == -1)
		ft_exit("pipex ERROR : Infile pipe failed");
	index = 1;
	while (index > 0)
	{
		index = read(fd, buffer, 1);
		if (index < 0)
			ft_putendl_fd("pipex WARNING : Infile read failed", 2);
		if (index == 0)
			break ;
		if (write(pipe_fd[1], buffer, 1) == -1)
			ft_exit("pipex ERROR : Infile write failed");
	}
	close (fd);
	close (pipe_fd[1]);
	return (pipe_fd[0]);
}
