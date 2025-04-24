/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_shape.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:53:13 by codespace         #+#    #+#             */
/*   Updated: 2025/03/25 13:52:34 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangular(int width, int height, int fd)
{
	if (width == height)
	{
		close(fd);
		print_message("Error\nMap is not rectangle.\n");
	}
}

void	check_consistent(int width, int first_width, int fd, char *line)
{
	if (width != first_width)
	{
		free_gnl(line, fd);
		close(fd);
		print_message("Error\nWalls not consistent.\n");
	}
}

void	validate_map_shape(char *filename)
{
	char	*line;
	int		width;
	int		height;
	int		first_width;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_message("Error\nFailed to open file.\n");
	line = get_next_line(fd);
	first_width = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
	height = 0;
	while (line)
	{
		width = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
		check_consistent(width, first_width, fd, line);
		free(line);
		height++;
		line = get_next_line(fd);
	}
	check_rectangular(width, height, fd);
	close(fd);
}
