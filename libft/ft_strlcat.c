/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:41:31 by yalkhidi          #+#    #+#             */
/*   Updated: 2024/12/28 12:14:11 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	total;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	total = dstlen + srclen;
	i = 0;
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	while (src[i] && (dstlen < dstsize - 1))
	{
		dst[dstlen] = src[i];
		i++;
		dstlen++;
	}
	dst[dstlen] = '\0';
	return (total);
}
