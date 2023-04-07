/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:23:42 by pferreir          #+#    #+#             */
/*   Updated: 2022/11/26 16:59:31 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char		*src2;
	unsigned char		*dest2;
	size_t				i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	if (dest2 > src2)
	{
		while (size-- > 0)
			dest2[size] = src2[size];
	}
	else
	{
		while (i < size)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	return (dest);
}
