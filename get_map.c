/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:39:26 by pferreir          #+#    #+#             */
/*   Updated: 2023/04/02 20:32:31 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	correct_file(const char *pathname)
{
	int	openfile;

	if (ft_strlen(ft_strnstr(pathname, ".ber", ft_strlen(pathname))) != 4)
		return (write (2, "Wrong map file!", 15));
	openfile = open(pathname, O_RDONLY);
	if (openfile == -1)
		return (write (2, "File can't be opened!", 21));
	return (openfile);
}

char	**get_map(int fd)
{
	char	*access;
	char	*lines;
	char	**res;

	access = NULL;
	lines = 0;
	while (1)
	{
		access = get_next_line(fd, 0);
		if (!access)
			break ;
		lines = ft_realloc(lines, access);
		if (access[0] == '\n')
		{
			free (lines);
			free (access);
			get_next_line(fd, 1);
			return (0);
		}
		free(access);
	}
	res = ft_split(lines, '\n');
	free (lines);
	return (res);
}
