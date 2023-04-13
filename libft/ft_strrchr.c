/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:24:52 by pferreir          #+#    #+#             */
/*   Updated: 2022/11/26 16:36:35 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	char_c;

	i = ft_strlen(s);
	char_c = (char)c;
	while (i >= 0)
	{
		if (s[i] == char_c)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
