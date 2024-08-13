/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:11:36 by pdeson            #+#    #+#             */
/*   Updated: 2024/02/22 16:57:39 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**paths;
	int		hrdc;
	int		fd_main;
	int		fd_out;
}	t_pipex;

# define ERR_ARGS 0
# define ERR_ENVP 127

void	ft_exit(const char *str);
void	ft_double_dup(int fd1, int fd2);
char	*ft_get_cmd(t_pipex pipex, int i);
char	**ft_get_paths(t_pipex pipex);
void	ft_outfile(t_pipex pipex);
int		ft_loop(t_pipex pipex, int i);
int		ft_heredoc(t_pipex *pipex);
int		ft_infile(t_pipex *pipex);
int		ft_check_args(int argc, char **argv);

#endif
