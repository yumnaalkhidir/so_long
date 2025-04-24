/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:37:44 by yalkhidi          #+#    #+#             */
/*   Updated: 2024/12/28 12:14:44 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	int		last;
	char	m;
	int		j;

	i = 0;
	last = 0;
	str = (char *)s;
	m = (char)c;
	j = 0;
	while (str[i])
	{
		if (str[i] == m)
		{
			j++;
			last = i;
		}
		i++;
	}
	if (str[i] == '\0' && m == '\0')
		return (&str[i]);
	if (j == 0)
		return (NULL);
	return (&str[last]);
}
