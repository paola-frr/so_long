/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:22:54 by pferreir          #+#    #+#             */
/*   Updated: 2022/11/26 16:56:08 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	n;
	int	i;
	int	signe;
	int	c;

	n = 0;
	i = 0;
	signe = 1;
	c = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-' )
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		c = nptr[i] - '0';
		n = 10 * n + c;
		i++;
	}
	return (n * signe);
}
