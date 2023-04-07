/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:31:59 by pferreir          #+#    #+#             */
/*   Updated: 2023/04/07 04:09:49 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		printf("%s\n", map[i++]);
}

int	key_hook(int keycode, t_data *data)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		img_width;
	int		img_height;

	img_width = 96;
	img_height = 96;
	(void)argv;
	if (argc != 2)
		return (write(2, "./so_long <map>\n", 17));
	data.map = get_map(correct_file(argv[1]));
	if (!data.map)
		return (write(1, "Error\n", 6));
	if (!check_errors(&data, data.map))
		write (2, "Error\n", 6);
		printf("lignes = %d, colonnes = %d\n", data.nbline, data.nbcol);
	data.mlx = mlx_init();
	//if (data.mlx == NULL)
	//	return (MLX_ERROR);
	data.mlx_win = mlx_new_window(data.mlx, 96 * data.nbcol, 96 * data.nbline, "so_long"); // fenetre largeur 1920 hauteur 1080 nom "Hello world!"
	data.img = mlx_new_image(data.mlx, 96 * data.nbcol, 96 * data.nbline); // init image de taille 1920*1080
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
		&data.line_length, &data.endian);
	data.fish = mlx_xpm_file_to_image(data.mlx, "./fish.xpm", &img_width, &img_height);
	data.shark = mlx_xpm_file_to_image(data.mlx, "./shark.xpm", &img_width, &img_height); // chercher nv requin
	data.wall = mlx_xpm_file_to_image(data.mlx, "./wall.xpm", &img_width, &img_height);
	data.ocean = mlx_xpm_file_to_image(data.mlx, "./ocean.xpm", &img_width, &img_height);
	data.cave = mlx_xpm_file_to_image(data.mlx, "./cave.xpm", &img_width, &img_height);
	ft_put_image_to_window(data);
	//mlx_hook(data.mlx_win, 17, 0, close, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &input, &data);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_loop(data.mlx); // mise en place fenetre de rendu
	return (0);
}

//convertir png en xpm puis redimensionner puis mettre image sur map
// ajouter compteur pour chaque mouvement
// reflechir aux mouvements
