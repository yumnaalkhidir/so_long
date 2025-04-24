/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:30:07 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/14 12:45:27 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	long_negative(int sign, long n, char c)
{
	if ((sign == -1) && ((n > LONG_MAX / 10) || (n == LONG_MAX / 10 && c - '0' \
	>= 8)))
		return (1);
	else
		return (0);
}

static int	long_positive(int sign, long n, char c)
{
	if ((sign == 1) && ((n > LONG_MAX / 10) || (n == LONG_MAX / 10 && c - '0' \
	>= 7)))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long long	output;
	int			sign;
	int			i;

	output = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (long_negative(sign, output, str[i]))
			return (0);
		else if (long_positive(sign, output, str[i]))
			return (-1);
		output = (output * 10) + (str[i] - '0');
		i++;
	}
	return ((sign * output));
}
