/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:54:48 by yalkhidi          #+#    #+#             */
/*   Updated: 2024/12/28 12:10:22 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!*lst)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone((*lst), del);
		(*lst) = next;
	}
	*lst = NULL;
}
