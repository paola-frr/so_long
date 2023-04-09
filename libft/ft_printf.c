/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:41:25 by pferreir          #+#    #+#             */
/*   Updated: 2023/04/09 02:14:19 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pointer(unsigned long n)
{
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		ft_putstr("0x");
		return (2 + ft_hexa(n, 1));
	}
}

void	print(char c, va_list args, int *i)
{
	if (c == '%')
		(*i) += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		(*i) += ft_putnbr(va_arg(args, int));
	else if (c == 'c')
		(*i) += ft_putchar(va_arg(args, int));
	else if (c == 's')
		(*i) += ft_putstr(va_arg(args, char *));
	else if (c == 'x')
		(*i) += ft_hexa(va_arg(args, unsigned int), 1);
	else if (c == 'X')
		(*i) += ft_hexa(va_arg(args, unsigned int), 0);
	else if (c == 'p')
	{
		(*i) += ft_pointer(va_arg(args, unsigned long));
	}
	else if (c == 'u')
		(*i) += ft_unsigned_int(va_arg(args, unsigned int));
	else
		(*i) += ft_putchar(c);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (i);
			print(*format, args, &i);
		}
		else
		{
			ft_putchar(*format);
			i++;
		}
		format++;
	}
	va_end(args);
	return (i);
}
