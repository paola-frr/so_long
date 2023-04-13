/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:01:56 by pferreir          #+#    #+#             */
/*   Updated: 2023/04/02 20:23:39 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*lit_buffer_size_caractere(int fd, char *temp)
{
	char	*une_lecture;
	long	reading;
	char	*s1;

	reading = 1;
	une_lecture = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (une_lecture == NULL)
		return (NULL);
	une_lecture[0] = 0;
	while (reading != 0 && ft_gnl_strchr(une_lecture, '\n') == 0)
	{
		reading = read(fd, une_lecture, BUFFER_SIZE);
		if (reading == -1)
		{
			free (une_lecture);
			return (NULL);
		}
		une_lecture[reading] = '\0';
		s1 = temp;
		temp = ft_gnl_strjoin(temp, une_lecture);
		free(s1);
	}
	free (une_lecture);
	return (temp);
}

char	*get_next_line(int fd, int erase)
{
	static char	*temp = NULL;
	char		*c;
	char		*line;
	size_t		i;

	i = 0;
	if (erase)
		return (free(temp), NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = lit_buffer_size_caractere(fd, temp);
	while (temp && temp[i] && temp[i] != '\n')
		i++;
	line = ft_gnl_substr(temp, 0, i + 1);
	c = temp;
	temp = ft_gnl_substr(temp, i + 1, ft_gnl_strlen(temp) - i);
	free(c);
	return (line);
}
