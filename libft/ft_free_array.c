/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:37:05 by pdeson            #+#    #+#             */
/*   Updated: 2024/02/12 10:01:41 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char ***array)
{
	size_t	i;

	i = 0;
	if (*array)
	{
		while (*(array) && (*array)[i])
		{
			free((*array)[i]);
			(*array)[i++] = NULL;
		}
		free(*array);
		*array = NULL;
	}
}
