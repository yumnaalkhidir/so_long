/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:28:12 by codespace         #+#    #+#             */
/*   Updated: 2025/03/17 14:32:15 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_elements(char *line, int *e, int *c, int *s)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'E')
			*e = *e + 1;
		else if (line[i] == 'P')
			*s = *s + 1;
		else if (line[i] == 'C')
			*c = 1;
		i++;
	}
}

void	check_elements2(char *line, int *wall, int *space)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			*wall = *wall + 1;
		else if (line[i] == '0')
			*space = *space + 1;
		i++;
	}
}

void	validate_map_elements(char	*filename)
{
	char	*line;
	int		exit;
	int		start;
	int		collectible;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_message("Error\nFailed to open file.\n");
	exit = 0;
	collectible = 0;
	start = 0;
	line = get_next_line(fd);
	while (line)
	{
		check_elements(line, &exit, &collectible, &start);
		free(line);
		line = get_next_line(fd);
	}
	if (!exit || !start || !collectible)
	{
		close(fd);
		print_message("Error\nMap is not complete.\n");
	}
	close(fd);
}

void	validate_map_elements2(char	*filename)
{
	char	*line;
	int		wall;
	int		space;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_message("Error\nFailed to open file.\n");
	space = 0;
	wall = 0;
	line = get_next_line(fd);
	while (line)
	{
		check_elements2(line, &wall, &space);
		free(line);
		line = get_next_line(fd);
	}
	if (!wall)
	{
		close(fd);
		print_message("Error\nMap is not complete.1\n");
	}
	close(fd);
}

void	validate_start_exit(char *filename)
{
	char	*line;
	int		exit;
	int		start;
	int		collectible;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_message("Error\nFailed to open file.\n");
	exit = 0;
	collectible = 0;
	start = 0;
	line = get_next_line(fd);
	while (line)
	{
		check_elements(line, &exit, &collectible, &start);
		free(line);
		line = get_next_line(fd);
	}
	if (start > 1 || exit > 1)
	{
		close(fd);
		print_message("Error\nMap contains more than one start/exit.\n");
	}
	close(fd);
}
