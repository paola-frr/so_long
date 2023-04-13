/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 03:00:22 by pferreir          #+#    #+#             */
/*   Updated: 2023/04/12 02:10:25 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_border(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j] != '\0')
	{
		if (map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	element_exist(char **map, t_data *data, int i)
{
	int	j;

	j = 0;
	while (map[i][j] != '\0')
	{
		if (map[i][j] == 'C')
			data->elem.c += 1;
		else if (map[i][j] == 'P')
		{
			data->elem.p += 1;
			data->px = i;
			data->py = j;
		}
		else if (map[i][j] == 'E')
		{
			data->elem.e += 1;
			data->ex = i;
			data->ey = j;
		}
		else if (map[i][j] != '0' && map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	transform_path(char **map, int i, int j)
{
	int	k;

	k = 0;
	if (map[i + 1][j] != '1' && map[i + 1][j] != 'E' && map[i + 1][j] != 'P')
	{
		map[i + 1][j] = 'P';
		k++;
	}
	if (map[i - 1][j] != '1' && map[i - 1][j] != 'E' && map[i - 1][j] != 'P')
	{
		map[i - 1][j] = 'P';
		k++;
	}
	if (map[i][j - 1] != '1' && map[i][j - 1] != 'E' && map[i][j - 1] != 'P')
	{
		map[i][j - 1] = 'P';
		k++;
	}
	if (map[i][j + 1] != '1' && map[i][j + 1] != 'E' && map[i][j + 1] != 'P')
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

int	search_ec(char **map, t_data *d)
{
	int		i;
	size_t	j;

	i = 1;
	j = 1;
	if (map[d->ex - 1][d->ey] == 'P' || map[d->ex + 1][d->ey] == 'P'
		|| map[d->ex][d->ey - 1] == 'P' || map[d->ex][d->ey + 1] == 'P')
		map[d->ex][d->ey] = 'P';
	while (map[i])
	{
		j = 1;
		while (j < ft_strlen(map[i]) - 1)
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
