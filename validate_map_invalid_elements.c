/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_invalid_elements.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:32:39 by codespace         #+#    #+#             */
/*   Updated: 2025/03/25 13:57:35 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_elements(char *line, int fd)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P')
		{
			free_gnl(line, fd);
			close(fd);
			print_message("Error\nInvalid element in map.\n");
		}
		i++;
	}
}

void	validate_invalid_elements(char *filename)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_message("Error\nFailed to open file.\n");
	line = get_next_line(fd);
	while (line)
	{
		invalid_elements(line, fd);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
