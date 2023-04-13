/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:23:01 by pferreir          #+#    #+#             */
/*   Updated: 2022/11/30 18:26:28 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*output;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (nmemb * size < size)
		return (0);
	output = (void *)malloc(nmemb * size);
	if (!output)
		return (NULL);
	ft_bzero(output, nmemb * size);
	return (output);
}
