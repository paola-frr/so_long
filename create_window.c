/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:09:17 by pferreir          #+#    #+#             */
/*   Updated: 2023/04/13 02:12:09 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_we_see_the_window(t_data *d)
{
	d->mlx = mlx_init();
	if (!d->mlx)
		return (0);
	d->win = mlx_new_window(d->mlx, 64 * d->nbcol, 64 * (d->nbline + 3), "so_long");
	if (!d->win)
		return (0);
	d->img = mlx_new_image(d->mlx, 64 * d->nbcol, 64 * d->nbline);
	if (!d->img)
		return (0);
	d->add = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length,
			&d->endian);
	d->fish = mlx_xpm_file_to_image(d->mlx, "./image/fish.xpm", &d->ih, &d->iw);
	d->wall = mlx_xpm_file_to_image(d->mlx, "./image/wall.xpm", &d->ih, &d->iw);
	d->sea = mlx_xpm_file_to_image(d->mlx, "./image/sea.xpm", &d->ih, &d->iw);
	d->cave = mlx_xpm_file_to_image(d->mlx, "./image/cave.xpm", &d->ih, &d->iw);
	d->ccave = mlx_xpm_file_to_image(d->mlx, "./image/ccave.xpm", &d->ih, &d->iw);
	d->b = mlx_xpm_file_to_image(d->mlx, "./image/b.xpm", &d->ih, &d->iw);
	d->h = mlx_xpm_file_to_image(d->mlx, "./image/h.xpm", &d->ih, &d->iw);
	d->g = mlx_xpm_file_to_image(d->mlx, "./image/g.xpm", &d->ih, &d->iw);
	d->d = mlx_xpm_file_to_image(d->mlx, "./image/d.xpm", &d->ih, &d->iw);
	if (!d->fish || !d->wall || !d->sea || !d->cave || !d->ccave
		|| !d->b || !d->h || !d->g || !d->d)
		return (0);
	return(1);
}

void	init_game(t_data *d)
{
	d->iw = 64;
	d->ih = 64;
	if (!can_we_see_the_window(d))
	{
		ft_printf("MLX ERROR");
		return ;
	}
	ft_put_image_to_window(d);
	mlx_hook(d->win, 2, 1, &input_data, d);
	mlx_hook(d->win, 17, 0, &close_win, d);
	mlx_loop(d->mlx);
}

void	ft_put_image_to_window(t_data *d)
{
	int	l;
	int	c;
	int	s;

	l = 0;
	s = 64;
	while (l != d->nbline)
	{
		c = 0;
		while (c != d->nbcol)
		{
			if (d->map[l][c] == '1')
				mlx_put_image_to_window(d->mlx, d->win, d->wall, c * s, l * s);
			if (d->map[l][c] == 'P')
				mlx_put_image_to_window(d->mlx, d->win, d->h, c * s, l * s);
			if (d->map[l][c] == '0')
				mlx_put_image_to_window(d->mlx, d->win, d->sea, c * s, l * s);
			if (d->map[l][c] == 'E')
				mlx_put_image_to_window(d->mlx, d->win, d->ccave, c * s, l * s);
			if (d->map[l][c] == 'C')
				mlx_put_image_to_window(d->mlx, d->win, d->fish, c * s, l * s);
			c++;
		}
		l++;
	}
}
