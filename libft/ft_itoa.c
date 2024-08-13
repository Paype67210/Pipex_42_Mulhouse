/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:35:40 by pdeson            #+#    #+#             */
/*   Updated: 2023/12/18 11:59:12 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cptchar(int nb)
{
	int	result;

	result = 1;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		result = 2;
		nb = -nb;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		result = result +1;
	}
	return (result);
}

char	*ft_itoa(long n)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_cptchar(n);
	str = malloc(((len + 1)) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (n > 0 && len > 0)
	{
		str[--len] = '0' + (n % 10);
		n = (n / 10);
	}
	return (str);
}
