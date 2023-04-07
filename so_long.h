/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:50:03 by pferreir          #+#    #+#             */
/*   Updated: 2023/04/07 04:12:16 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_position
{
	int	p[2];
	int	e[2];
}			t_position;

typedef struct s_element
{
	int	c;
	int	e;
	int	p;
}				t_element;

typedef struct s_data
{
	char		**map;
	int			posx;
	int			posy;
	t_element	elem;
	int			nbline;
	int			nbcol;
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			img_height;
	int			img_width;
	void		*fish;
	void		*shark;
	void		*wall;
	void		*ocean;
	void		*cave;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			fposx;
	int			fposy;
}				t_data;

void	print_map(char **map);
int		correct_file(const char *pathname);
char	**get_map(int fd);
int		check_border(char **map, int i);
int		element_exist(char **map, t_data *data, int i);
int		check_errors(t_data *data, char **map);
int		close_map(char **map);
int		check_element(t_data *data, char **map);
int		check_rectangular_shaped(t_data *data);
void	check_path(char **map);
int		transform_path(char **map, int i, int j);
int		search_ec(char **map);
char	**dup_map(char **map);
void	ft_put_image_to_window(t_data data);

#endif