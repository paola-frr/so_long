/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:09:17 by pferreir          #+#    #+#             */
/*   Updated: 2023/04/07 04:13:07 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image_to_window(t_data data)
{
	int	l;
	int	c;


	l = 0;
	while (l != data.nbline)
	{
		c = 0;
		while (c != data.nbcol)
		{
			if (data.map[l][c] == '1')
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.wall, c * 96, l * 96);
			if (data.map[l][c] == 'P')
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.shark, c * 96, l * 96);
			if (data.map[l][c] == '0')
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.ocean, c * 96, l * 96);
			if (data.map[l][c] == 'E')
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.cave, c * 96, l * 96);
			if (data.map[l][c] == 'C')
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.fish, c * 96, l * 96);
			c++;
		}
		l++;
	}

}

/*int	input(int key, t_data *data)
{
	data->fposx = data->posx;
	data->fposy = data->posy;
	mlx_clear_window(data->mlx, data->mlx_win);
	if (key == 65307)
		//free_win(data);
	if (key == 100)
		data->fposx += 1;
	else if (key == 97)
		data->futurposx -= 1;
	else if (key == 115)
		data->futurposy += 1;
	else if (key == 119)
		data->futurposy -= 1;
	if (key == 100)
		data->facing = 0;
	if (key == 97)
		data->facing = 1;
	//check_moove(data, key);
	return (0);
}*/