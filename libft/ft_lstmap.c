/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:25:07 by yalkhidi          #+#    #+#             */
/*   Updated: 2024/12/26 19:10:04 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;

	new_list = NULL;
	while (lst)
	{
		node = (t_list *)malloc(sizeof(t_list));
		if (!node)
		{
			ft_lstclear(&node, del);
			return (NULL);
		}
		node ->content = f(lst->content);
		node ->next = NULL;
		ft_lstadd_back(&new_list, node);
		lst = lst->next;
	}
	return (new_list);
}
