/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:45:06 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/18 14:37:46 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_end(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*extract_line(char **buff)
{
	char	*line;
	char	*new_buff;
	int		newline_index;

	newline_index = check_end(*buff);
	if ((*buff)[newline_index] == '\n')
	{
		line = ft_substrs(*buff, 0, newline_index + 1);
		if (!line)
			return (free(*buff), *buff = NULL, NULL);
		new_buff = ft_strdups(*buff + newline_index + 1);
		if (!new_buff)
			return (free(line), free(*buff), *buff = NULL, NULL);
		free(*buff);
		*buff = new_buff;
	}
	else
	{
		line = ft_strdups(*buff);
		free(*buff);
		*buff = NULL;
	}
	return (line);
}

char	*read_to_buff(char *buffer, int fd, int *endof)
{
	char	*temp;
	char	read_buff[BUFFER_SIZE + 1];
	ssize_t	length;

	length = read(fd, read_buff, BUFFER_SIZE);
	*endof = length;
	if (length < 0)
	{
		free(buffer);
		return (NULL);
	}
	read_buff[length] = '\0';
	if (!buffer)
		return (ft_strdups(read_buff));
	temp = ft_strjoins(buffer, read_buff);
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			endof;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	endof = 1;
	while (!check_end(buffer) && endof != 0)
	{
		buffer = read_to_buff(buffer, fd, &endof);
		if (!buffer)
			return (NULL);
	}
	if (endof == 0 && (buffer[0] == '\0'))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = extract_line(&buffer);
	return (line);
}
