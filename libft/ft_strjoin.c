/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:12:16 by pdeson            #+#    #+#             */
/*   Updated: 2024/02/22 16:05:00 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	int		i;
	int		j;

	if (!s1 && !s2)
		exit (EXIT_FAILURE);
	buffer = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!buffer)
		exit (EXIT_FAILURE);
	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
	{
		buffer[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		buffer[i + j] = s2[j];
		j++;
	}
	buffer[i + j] = '\0';
	return (buffer);
}
