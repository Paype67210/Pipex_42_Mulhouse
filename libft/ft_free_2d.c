/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:41:10 by pdeson            #+#    #+#             */
/*   Updated: 2024/02/12 08:46:09 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_2d(char **array)
{
	size_t	i;

	i = 0;
	if (array)
	{
		while (array && array[i])
		{
			if (array[i] == NULL)
				free(array[i]);
			array[i++] = NULL;
		}
		free(array);
		array = NULL;
	}
}
