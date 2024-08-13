/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:09:29 by pdeson            #+#    #+#             */
/*   Updated: 2024/02/26 09:39:58 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	size_t	i;
	size_t	lenbuff;

	if (!s || start >= ft_strlen(s))
		return (NULL);
	if (start + len > ft_strlen(s))
		lenbuff = ft_strlen(s) - start;
	else if (len > ft_strlen(s))
		lenbuff = ft_strlen(s);
	else
		lenbuff = len;
	buffer = (char *)malloc(lenbuff + 1);
	if (!buffer)
		exit (EXIT_FAILURE);
	i = 0;
	while (s[start + i] && i < len)
	{
		buffer[i] = s[start + i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
