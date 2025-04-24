/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:18:57 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/25 14:03:47 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char s, char c)
{
	if (c == s)
		return (1);
	else
		return (0);
}

static int	words_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] && check(s[i], c))
		i++;
	while (s[i])
	{
		if (!check(s[i], c))
		{
			count++;
			while (s[i] && !check(s[i], c))
				i++;
		}
		while (s[i] && check(s[i], c))
			i++;
	}
	return (count);
}

static char	*copy_word(char const *src, int start, int len)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = src[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	int		a;
	char	**split;

	words = words_count(s, c);
	split = (char **)malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	a = 0;
	while (s[i])
	{
		while (s[i] && check(s[i], c))
			i++;
		words = 0;
		while (s[i + words] && !check(s[i + words], c))
			words++;
		if (words > 0)
			split[a++] = copy_word(s, i, words);
		i += words;
	}
	split[a] = NULL;
	return (split);
}
