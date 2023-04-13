/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:31:59 by pferreir          #+#    #+#             */
/*   Updated: 2023/04/13 02:00:18 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(t_data *data)
{
	ft_printf("%d\n", data->counter);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	if (argc != 2)
		return (ft_printf("%r./so_long <map>%0\n"));
	ft_memset(& data, 0, sizeof(data));
	ft_printf("%d\n", data.counter);
	data.map = get_map(correct_file(argv[1]));
	if (!data.map)
		return (ft_printf("%rFile's error%0\n", 20), ft_freetab(data.map), 0);
	if (!check_errors(&data, data.map))
		return(ft_freetab(data.map), 0);
	init_game(&data);
	return (0);
}
