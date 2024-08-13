/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:11:36 by pdeson            #+#    #+#             */
/*   Updated: 2024/02/26 12:24:52 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../headers/libft.h"

void	ft_double_dup(int fd1, int fd2)
{
	if (dup2(fd1, STDIN_FILENO) == -1)
		ft_exit("pipex ERROR : STDIN dup failed");
	if (dup2(fd2, STDOUT_FILENO) == -1)
		ft_exit("pipex ERROR : STDOUT dup failed");
}

static char	*ft_get_file(t_pipex pipex, char *cmd)
{
	int		i;
	char	*tmp;
	char	*file;

	i = 0;
	file = NULL;
	while (pipex.paths[i])
	{
		tmp = file;
		file = ft_strjoin(pipex.paths[i], cmd);
		free (tmp);
		if (!access (file, F_OK))
			break ;
		i++;
	}
	if (access(file, F_OK) == -1)
	{
		free (file);
		ft_free_array(&pipex.paths);
		ft_putendl_fd("pipex WARNING : Command not found", 2);
		return (NULL);
	}
	return (file);
}

char	*ft_get_cmd(t_pipex pipex, int i)
{
	char	*cmd;
	char	*file;

	if (ft_int_strchr(pipex.argv[i], ' ') > 0)
		cmd = ft_substr(pipex.argv[i], 0, ft_int_strchr(pipex.argv[i], ' '));
	else
		cmd = ft_substr(pipex.argv[i], 0, ft_strlen(pipex.argv[i]));
	if (!access(cmd, F_OK))
		return (cmd);
	file = ft_get_file(pipex, cmd);
	free (cmd);
	return (file);
}

char	**ft_get_paths(t_pipex pipex)
{
	char	**paths;
	char	*tmp;
	int		i;

	i = 0;
	while (ft_strncmp(pipex.envp[i], "PATH=", 5))
		i++;
	paths = ft_split(&pipex.envp[i][5], ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free (tmp);
		i++;
	}
	return (paths);
}
