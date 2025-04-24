/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_elements_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:28:12 by codespace         #+#    #+#             */
/*   Updated: 2025/04/08 16:21:39 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_elements_bonus(char *line, int *wall, int *space, int *sprite)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			*wall = *wall + 1;
		else if (line[i] == '0')
			*space = *space + 1;
		else if (line[i] == 'S')
			*sprite = *sprite + 1;
		i++;
	}
}

void	validate_map_elements_bonus(char *filename)
{
	char	*line;
	int		wall;
	int		space;
	int		fd;
	int		sprite;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_message("Error\nFailed to open file.\n");
	space = 0;
	wall = 0;
	sprite = 0;
	line = get_next_line(fd);
	while (line)
	{
		check_elements_bonus(line, &wall, &space, &sprite);
		free(line);
		line = get_next_line(fd);
	}
	if (!wall || sprite < 1)
	{
		close(fd);
		print_message("Error\nMap is not complete.\n");
	}
	close(fd);
}
