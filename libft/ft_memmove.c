/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:54:42 by yalkhidi          #+#    #+#             */
/*   Updated: 2024/12/28 12:12:16 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest_ptr;
	char	*src_ptr;
	size_t	i;

	dest_ptr = (char *)dst;
	src_ptr = (char *)src;
	if (dest_ptr > src_ptr)
	{
		i = len - 1;
		while (i <= len)
		{
			dest_ptr[i] = src_ptr[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
