/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:31:59 by pferreir          #+#    #+#             */
/*   Updated: 2023/04/09 03:09:44 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	printf("%d\n", data->counter);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	if (argc != 2)
		return (write(2, "./so_long <map>\n", 17));
	data.map = get_map(correct_file(argv[1]));
	if (!data.map)
		return (write(1, "Error\n", 6));
	if (!check_errors(&data, data.map))
		write (2, "Error\n", 6);
	init_game(data);
	return (0);
}
