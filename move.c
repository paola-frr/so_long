/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:59:45 by pferreir          #+#    #+#             */
/*   Updated: 2023/04/09 05:13:52 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

int	input_data(int key, t_data *d)
{
	if (key == 65307)
		return (close_win(d));
	else if (key == 100 || key == 65363)
		make_move(d, key, 0, 1);
	else if (key == 97 || key == 65361)
		make_move(d, key, 0, -1);
	else if (key == 115 || key == 65364)
		make_move(d, key, 1, 0);
	else if (key == 119 || key == 65362)
		make_move(d, key, -1, 0);
	return (0);
}

void	*direction(t_data *d, int x, int y)
{
	if (x == 0 && y == 1)
		return (d->d);
	else if (x == 0 && y == -1)
		return (d->g);
	else if (x == 1 && y == 0)
		return (d->b);
	else
		return (d->h);
}

void	open_exit(t_data *d)
{
	int	s;

	s = 64;
	if (d->elem.c == 0)
	{
		d->elem.e = 0;
		mlx_put_image_to_window(d->mlx, d->win, d->cave, d->ey * s, d->ex * s);
	}
}

void	make_move(t_data *d, int key, int x, int y)
{
	void	*m;

	m = direction(d, x, y);
	if (d->map[d->px + x][d->py + y] == 'E')
	{
		if (d->elem.e == 0)
			close_win(d);
		mlx_put_image_to_window(d->mlx, d->win, m, d->py * 64, d->px * 64);
	}
	else if (d->map[d->px + x][d->py + y] != '1')
	{
		if (d->map[d->px + x][d->py + y] == 'C')
		{
			d->map[d->px + x][d->py + y] = '0';
			d->elem.c--;
			open_exit(d);
		}
		mlx_put_image_to_window(d->mlx, d->win, d->sea, d->py * 64, d->px * 64);
		d->px += x;
		d->py += y;
		mlx_put_image_to_window(d->mlx, d->win, m, d->py * 64, d->px * 64);
		d->counter++;
	}
	else
		mlx_put_image_to_window(d->mlx, d->win, m, d->py * 64, d->px * 64);
}

int	close_win(t_data *d)
{
	mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_image(d->mlx, d->fish);
	mlx_destroy_image(d->mlx, d->shark);
	mlx_destroy_image(d->mlx, d->wall);
	mlx_destroy_image(d->mlx, d->sea);
	mlx_destroy_image(d->mlx, d->cave);
	mlx_destroy_image(d->mlx, d->ccave);
	mlx_destroy_image(d->mlx, d->h);
	mlx_destroy_image(d->mlx, d->b);
	mlx_destroy_image(d->mlx, d->g);
	mlx_destroy_image(d->mlx, d->d);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	ft_freetab(d->map);
	exit (0);
	return (0);
}
