/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:23:21 by pferreir          #+#    #+#             */
/*   Updated: 2022/11/26 16:39:01 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_caractere(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*nbr;
	long int	m;

	m = (long int)n;
	len = nb_caractere(n);
	nbr = (char *)malloc((len + 1) * sizeof(char));
	if (nbr == NULL)
		return (NULL);
	nbr[len] = '\0';
	if (n < 0)
		m = -m;
	while (--len > -1)
	{
		nbr[len] = (m % 10) + 48;
		m = m / 10;
	}
	if (n < 0)
		nbr[0] = '-';
	return (nbr);
}
