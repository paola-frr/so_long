/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 04:52:21 by pferreir          #+#    #+#             */
/*   Updated: 2023/04/02 20:31:54 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	transform_path(char **map, int i, int j)
{
	int	k;

	k = 0;
	if (map[i + 1][j] != '1' && map[i + 1][j] != 'P')
	{
		map[i + 1][j] = 'P';
		k++;
	}
	if (map[i - 1][j] != '1' && map[i - 1][j] != 'P')
	{
		map[i - 1][j] = 'P';
		k++;
	}
	if (map[i][j - 1] != '1' && map[i][j - 1] != 'P')
	{
		map[i][j - 1] = 'P';
		k++;
	}
	if (map[i][j + 1] != '1' && map[i][j + 1] != 'P')
	{
		map[i][j + 1] = 'P';
		k++;
	}
	return (k);
}

void	check_path(char **map)
{
	int		i;
	size_t	j;
	int		count;

	i = 1;
	count = 0;
	while (map[i])
	{
		j = 1;
		while (j < ft_strlen(map[i]) - 1)
		{
			if (map[i][j] == 'P')
				count += transform_path(map, i, j);
			j++;
		}
		i++;
	}
	if (count > 0)
		check_path(map);
}

int	search_ec(char **map)
{
	int		i;
	size_t	j;

	i = 1;
	j = 1;
	while (map[i])
	{
		j = 1;
		while (j < ft_strlen(map[i]) - 1)
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
