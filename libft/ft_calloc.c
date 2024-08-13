/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 08:50:00 by pdeson            #+#    #+#             */
/*   Updated: 2023/10/26 15:48:07 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	memsize;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	memsize = nmemb * size;
	if (memsize / size != nmemb)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	else
		ft_memset(ptr, 0, memsize);
	return (ptr);
}
