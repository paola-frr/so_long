/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:24:08 by pferreir          #+#    #+#             */
/*   Updated: 2023/04/02 20:05:40 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static char	*ft_strdup1(char *str, char c)
{
	char	*mot;
	int		i;
	int		taille_mot;

	taille_mot = 0;
	i = 0;
	while (str[taille_mot] != '\0' && str[taille_mot] != c)
		taille_mot++;
	mot = (char *)malloc((taille_mot + 1) * sizeof(char));
	if (mot == NULL)
		return (NULL);
	while (str[i] != '\0' && str[i] != c)
	{
		mot[i] = str[i];
		i++;
	}
	mot[i] = 0;
	return (mot);
}

static int	countwords(char *str, char c)
{
	int	nb_mot;

	nb_mot = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			nb_mot++;
		}
		while (*str && *str != c)
			str++;
	}
	return (nb_mot);
}

char	**ft_split(char *str, char c)
{
	int		i;
	char	**tab;

	i = 0;
	if (!str)
		return (NULL);
	tab = ft_calloc((countwords(str, c) + 1), sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (str && *str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			tab[i] = ft_strdup1(str, c);
			if (tab[i] == NULL)
				return (ft_freetab(tab), NULL);
			i++;
		}
		while (*str && *str != c)
			str++;
	}
	free(str);
	return (tab);
}*/

int	count(char const *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] == '\0')
			break ;
		counter++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (counter);
}

char	*ft_strtsub(char const *str, int start, int end)
{
	int		i;
	char	*var;

	i = 0;
	var = malloc(sizeof(char) * end - start + 1);
	if (!var)
		return (NULL);
	while (((start + i) < end) && str[i])
	{
		var[i] = str[start + i];
		i++;
	}
	var[i] = '\0';
	return (var);
}

char	**to_tab(char **tab, char const *s, char c, int count)
{
	int	i;
	int	index;
	int	start;

	i = 0;
	index = 0;
	while (index < count)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && (s[i] != c))
			i++;
		tab[index] = ft_strtsub(s, start, i);
		if (!tab[index])
		{
			//ft_freetab(tab);
			return (NULL);
		}
		index++;
	}
	return (tab);
}

char	**ft_split(char *s, char c)
{
	int		nb;
	char	**tab;

	if (s == 0)
		return (NULL);
	nb = count(s, c);
	tab = malloc(sizeof(char *) * (nb + 1));
	if (!tab)
		return (NULL);
	tab = to_tab(tab, s, c, nb);
	*(tab + nb) = NULL;
	return (tab);
}