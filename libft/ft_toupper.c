/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:25:06 by pferreir          #+#    #+#             */
/*   Updated: 2022/11/18 13:40:21 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	char	lettre;

	lettre = (char) c;
	if (lettre >= 'a' && lettre <= 'z')
		lettre -= 32;
	return (lettre);
}
