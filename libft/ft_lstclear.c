/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:21:04 by pferreir          #+#    #+#             */
/*   Updated: 2022/11/27 15:09:03 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp1;
	t_list	*temp2;

	if (lst)
	{
		temp1 = *lst;
		while (temp1)
		{
			temp2 = temp1;
			temp1 = temp1->next;
			(*del)(temp2->content);
			free(temp2);
			temp2 = 0;
		}
	}
	*lst = 0;
}
