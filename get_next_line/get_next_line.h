/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:02:31 by pferreir          #+#    #+#             */
/*   Updated: 2023/04/02 20:20:30 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_gnl_strjoin(char *s1, char *s2);
size_t	ft_gnl_strlen(char *s);
char	*get_next_line(int fd, int erase);
char	*ft_gnl_strchr(char *s, int c);
char	*ft_gnl_substr(char *s, unsigned int start, size_t len);
char	*lit_buffer_size_caractere(int fd, char *temp);

#endif