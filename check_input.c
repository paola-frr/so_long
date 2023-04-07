/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:12:44 by pferreir          #+#    #+#             */
/*   Updated: 2023/04/07 03:56:38 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_errors(t_data *data, char **map)
{
	char	**map_bis;

	map_bis = dup_map(map);
	if (!check_rectangular_shaped(data))
		return (ft_freetab(map_bis), write (2, "WRONG SIZE !\n", 22), 0);
	if (!close_map(map))
		return (ft_freetab(map_bis), write (2, "UNCLOSED !\n", 18), 0);
	if (!check_element(data, map))
		return (ft_freetab(map_bis), write (2, "CHECK CARACTERS !\n", 30), 0);
	check_path(map_bis);
	if (!search_ec(map_bis))
		return (ft_freetab(map_bis), write (2, "NO PATH !\n", 19), 0);
	return (ft_freetab(map_bis), 1);
}

int	close_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
	{
		if (i == 0)
		{
			if (!check_border(map, i))
				return (0);
		}
		else if (map[i + 1] != NULL)
		{
			if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
				return (0);
		}
		else
		{
			if (!check_border(map, i))
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_element(t_data *data, char **map)
{
	int			i;

	i = 0;
	ft_memset(&data->elem, 0, sizeof(data->elem));
	while (map && map[i])
	{
		if (!element_exist(map, data, i))
			return (0);
		i++;
	}
	if (data->elem.c < 1 || data->elem.e != 1 || data->elem.p != 1)
	{
		write(2, "There is a problem with your map\n", 33);
		return (0);
	}
	return (1);
}

int	check_rectangular_shaped(t_data *data)
{
	data->nbline = 0;
	data->nbcol = ft_strlen(data->map[data->nbline]);
	while (data->map && data->map[data->nbline])
	{
		if (ft_strlen(data->map[data->nbline]) != data->nbcol)
			return (0);
		data->nbline++;
	}
	return (1);
}

char	**dup_map(char **map)
{
	int		i;
	char	**res;
	char	*map_dup;

	i = 0;
	map_dup = 0;
	while (map && map[i])
	{
		map_dup = ft_realloc(map_dup, map[i]);
		map_dup = ft_realloc(map_dup, "\n");
		i++;
	}
	res = ft_split(map_dup, '\n');
	free(map_dup);
	return (res);
}
