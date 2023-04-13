/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:50:03 by pferreir          #+#    #+#             */
/*   Updated: 2023/04/13 02:03:20 by pferreir         ###   ########.fr       */
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

typedef struct s_element
{
	int	c;
	int	e;
	int	p;
}				t_element;

typedef struct s_data
{
	char		**map;
	int			px;
	int			py;
	int			ex;
	int			ey;
	t_element	elem;
	int			nbline;
	int			nbcol;
	void		*mlx;
	void		*win;
	void		*img;
	char		*add;
	int			ih;
	int			iw;
	void		*fish;
	void		*shark;
	void		*wall;
	void		*sea;
	void		*cave;
	void		*ccave;
	void		*b;
	void		*h;
	void		*d;
	void		*g;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			counter;
}				t_data;

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
int		search_ec(char **map, t_data *data);
char	**dup_map(char **map);
void	ft_put_image_to_window(t_data *data);

int		check_input_data(t_data *data, int key);
int		input_data(int key, t_data *data);
int		close_win(t_data *data);
int		key_hook(t_data *data);

void	init_game(t_data *data);
int		can_we_see_the_window(t_data *d);
void	make_move(t_data *d, int x, int y);

void	*direction(t_data *d, int x, int y);
void	open_exit(t_data *d);

#endif