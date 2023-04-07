/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:23:31 by pferreir          #+#    #+#             */
/*   Updated: 2022/11/26 16:36:20 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*char_s;
	unsigned char	char_c;
	size_t			i;

	i = 0;
	char_s = (unsigned char *)s;
	char_c = (unsigned char)c;
	while (char_s && i < n)
	{
		if (char_s[i] == char_c)
			return (char_s + i);
		i++;
	}
	return (NULL);
}
