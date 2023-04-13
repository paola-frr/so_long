/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:24:28 by pferreir          #+#    #+#             */
/*   Updated: 2022/11/26 16:36:04 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	i;

	len_d = ft_strlen(dst);
	i = 0;
	if (size <= len_d)
		return (size + ft_strlen(src));
	while (src[i] != '\0' && i + len_d < size - 1)
	{
		dst[i + len_d] = src[i];
		i++;
	}
	dst[i + len_d] = '\0';
	return (len_d + ft_strlen(src));
}
