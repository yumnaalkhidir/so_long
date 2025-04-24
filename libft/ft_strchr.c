/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:24:40 by yalkhidi          #+#    #+#             */
/*   Updated: 2024/12/28 12:13:05 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	m;

	str = (char *)s;
	m = (char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == m)
			return (&str[i]);
		i++;
	}
	if (m == '\0' && str[i] == '\0')
		return (&str[i]);
	return (NULL);
}
