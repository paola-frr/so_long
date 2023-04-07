/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:17:29 by pferreir          #+#    #+#             */
/*   Updated: 2023/03/28 01:23:20 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s = malloc(sizeof(char) * (ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1));
	if (s == NULL)
		return (NULL);
	while (s1 && s1[j])
	{
		s[j] = s1[j];
		j++;
	}
	while (s2 && s2[i])
	{
		s[i + j] = s2[i];
		i++;
	}
	s[i + j] = '\0';
	return (s);
}

size_t	ft_gnl_strlen(char *s)
{
	size_t	i;

	if (s == NULL || s[0] == '\0')
		return (0);
	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_gnl_strchr(char *s, int c)
{
	int		i;
	char	lettre;

	lettre = (char)c;
	i = 0;
	if (lettre == '\0')
		return ((char *)s + ft_gnl_strlen((char *)s));
	while (s && s[i] && s[i] != '\0')
	{
		if (s[i] == lettre)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_gnl_substr(char *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*str;

	i = 0;
	if (start > ft_gnl_strlen(s))
		return (NULL);
	if (ft_gnl_strlen(s) - (size_t)start < len)
		len = ft_gnl_strlen(s) - (size_t)start;
	str = malloc(sizeof(char) * (len + 1));
	while (s && s[start] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	if (str[0] == '\0' || str == NULL || ft_gnl_strlen(s) < start)
	{
		free (str);
		return (NULL);
	}
	return (str);
}
