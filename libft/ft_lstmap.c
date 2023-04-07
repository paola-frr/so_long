/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferreir <pferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:29:37 by pferreir          #+#    #+#             */
/*   Updated: 2022/11/27 15:55:35 by pferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp1;
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = ft_lstnew((*f)(lst->content));
	if (!tmp)
		return (0);
	temp1 = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = ft_lstnew((*f)(lst->content));
		if (tmp->next == NULL)
		{
			ft_lstclear(&temp1, del);
			return (0);
		}
		tmp = tmp->next;
	}
	return (temp1);
}
