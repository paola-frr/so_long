/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:41:32 by pferreir          #+#    #+#             */
/*   Updated: 2023/04/13 01:21:54 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_unsigned_int(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		i += (ft_unsigned_int(nb / 10));
		i += (ft_unsigned_int(nb % 10));
	}
	else
		i += (ft_putchar(nb + 48));
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		i += ft_putstr("-2147483648");
		return (i);
	}
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else
		i += ft_putchar(nb + 48);
	return (i);
}

int	ft_hexa(unsigned long nb, int s)
{
	int	i;

	i = 0;
	if (nb >= 16)
	{
		i += ft_hexa(nb / 16, s);
	}
	if (nb % 16 < 10)
	{
		i += ft_putchar((nb % 16) + 48);
	}
	else
	{
		if (s == 1)
			i += ft_putchar((nb % 16) + 87);
		else
			i += ft_putchar((nb % 16) + 55);
	}
	return (i);
}
