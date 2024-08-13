/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:11:36 by pdeson            #+#    #+#             */
/*   Updated: 2024/02/26 11:00:55 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"
#include "../headers/libft.h"

void	ft_exit(const char *str)
{
	if (str)
		exit(ft_msg(strerror(errno), "", "", 1));
	else
		exit (ft_msg("", "", "", 0));
}

static t_pipex	ft_create_pipex(int argc, char **argv, char **envp)
{
	t_pipex	buffer;

	buffer.argc = argc;
	buffer.argv = argv;
	buffer.envp = envp;
	buffer.fd_main = -1;
	buffer.fd_out = -1;
	buffer.hrdc = 1;
	buffer.paths = NULL;
	return (buffer);
}

static t_pipex	ft_init(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	pipex = ft_create_pipex(argc, argv, envp);
	pipex.paths = ft_get_paths(pipex);
	if (!argv[1] || !argv[1][0])
		ft_exit("pipex ERROR : First arg not valid");
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc") + 1))
		pipex.fd_out = open(argv[argc - 1], \
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
	{
		pipex.hrdc = 0;
		if (access(argv[1], F_OK | R_OK) == -1)
			ft_putendl_fd("Pipex WARNING : Infile does \
				not exist or permission denied", 2);
		pipex.fd_out = open(argv[argc - 1], \
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (pipex.fd_out < 0)
		ft_putendl_fd("Pipex WARNING : Outfile open failed", 2);
	if (access(argv[argc - 1], W_OK) == -1)
		ft_putendl_fd("Pipex WARNING : Outfile permission denied", 2);
	return (pipex);
}

static void	ft_get_inout_puts(t_pipex *pipex)
{
	if (pipex->hrdc == 1)
		pipex->fd_main = ft_heredoc(pipex);
	else
		pipex->fd_main = ft_infile(pipex);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		i;

	errno = 0;
	if (!envp || envp[0][0] == '\0')
		exit(ft_msg("ENVP Error", "", "", ERR_ENVP));
	if (ft_check_args(argc, argv) > 1)
		exit(ft_msg("ARGS Error", "", "", ERR_ARGS));
	pipex = ft_init(argc, argv, envp);
	ft_get_inout_puts(&pipex);
	i = 2 + pipex.hrdc;
	while (i < argc - 1)
		pipex.fd_main = ft_loop(pipex, i++);
	while (i > 2 + pipex.hrdc)
	{
		if (waitpid(-1, 0, 0) == -1)
			ft_exit("pipex ERROR : Waitpid failed");
		i--;
	}
	ft_outfile(pipex);
	ft_free_array(&pipex.paths);
	exit(0);
	return (0);
}
