/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:24:12 by pferreir          #+#    #+#             */
/*   Updated: 2022/11/22 20:46:04 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	lettre;

	lettre = (char)c;
	i = 0;
	if (lettre == '\0')
		return ((char *)s + ft_strlen((char *)s));
	while (s[i])
	{
		if (s[i] == lettre)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (0);
}
