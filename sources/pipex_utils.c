/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:11:36 by pdeson            #+#    #+#             */
/*   Updated: 2024/02/26 10:45:11 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../headers/libft.h"

static int	ft_check_cmds(int argc, char **argv)
{
	int	i;
	int	result;

	result = 1;
	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0 || ft_strlen(argv[i]) == 0)
			result = 502;
		i++;
	}
	return (result);
}

static int	ft_check_inoutputs(char *infile, char *outfile)
{
	int	result;
	int	fd_file;

	result = 1;
	if (access(infile, F_OK | R_OK) == -1)
		result = ft_msg(strerror(errno), ": ", infile, 404);
	fd_file = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_file == -1)
		result = ft_msg(strerror(errno), ": ", outfile, 404);
	close(fd_file);
	if (access(outfile, R_OK | W_OK) == -1)
		result = ft_msg(strerror(errno), ": ", "Output File permissions", 404);
	return (result);
}

int	ft_check_args(int argc, char **argv)
{
	int	result;

	if (argc != 5)
	{
		result = (ft_msg("Grammar : ", \
			"./pipex file1 cmd1 cmd2 file2", "", 503));
	}
	else
	{
		result = ft_check_cmds(argc, argv);
		if (result == 1)
			result = ft_check_inoutputs(argv[1], argv[argc - 1]);
	}
	return (result);
}
