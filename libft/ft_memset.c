/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:37:51 by yalkhidi          #+#    #+#             */
/*   Updated: 2024/12/18 16:12:49 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	k;
	unsigned char	*s;
	size_t			i;

	k = (unsigned char) c;
	s = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		s[i] = k;
		i++;
	}
	return (b);
}
