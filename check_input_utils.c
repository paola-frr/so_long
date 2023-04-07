/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 03:00:22 by pferreir          #+#    #+#             */
/*   Updated: 2023/04/01 02:03:50 by pferreir         ###   ########.fr       */
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
			data->pos.p[0] = i;
			data->pos.p[1] = j;
		}
		else if (map[i][j] == 'E')
		{
			data->elem.e += 1;
			data->pos.e[0] = i;
			data->pos.e[1] = j;
		}
		else if (map[i][j] != '0' && map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}
