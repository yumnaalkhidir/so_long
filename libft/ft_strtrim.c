/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:08:31 by yalkhidi          #+#    #+#             */
/*   Updated: 2024/12/28 13:48:24 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		begin;
	int		end;

	if (!s1 || !set)
		return (NULL);
	begin = 0;
	end = ft_strlen(s1);
	while (s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	while (end > begin && ft_strchr(set, s1[end - 1]))
		end--;
	if (end <= begin)
	{
		trimmed = (char *)malloc(1 * sizeof(char));
		if (!trimmed)
			return (NULL);
		trimmed[0] = '\0';
		return (trimmed);
	}
	trimmed = (char *)malloc((end - begin + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_strncpy(trimmed, &s1[begin], end - begin);
	return (trimmed);
}
