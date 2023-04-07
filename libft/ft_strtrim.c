/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:24:55 by pferreir          #+#    #+#             */
/*   Updated: 2022/11/26 17:06:17 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_trim(char const c, char const *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (c == s2[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	int		i;
	char	*trimmer;
	int		j;
	int		k;
	int		taille_trim;

	i = 0;
	j = ft_strlen(s1);
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	while (is_trim(s1[i], s2))
		i++;
	while (is_trim(s1[j - 1], s2) && j > i + 1)
		j--;
	trimmer = (char *)malloc((j - i + 1) * sizeof(char));
	if (trimmer == NULL )
		return (NULL);
	taille_trim = j - i + 1;
	while (k < taille_trim)
		trimmer[k++] = s1[i++];
	trimmer[taille_trim - 1] = '\0';
	return (trimmer);
}
