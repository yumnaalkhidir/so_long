/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:53:26 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/21 14:29:53 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_to_array(char *filename, t_area *area)
{
	int		fd;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_message("Error\nFailed to open file");
	area->map = (char **)malloc((area->height + 1) * sizeof(char *));
	if (!area->map)
	{
		close(fd);
		print_message("Error\nAllocation Failed");
	}
	y = 0;
	while (y < area->height)
	{
		area->map[y] = get_next_line(fd);
		y++;
	}
	area->map[y] = NULL;
	close(fd);
}

void	find_player(t_area *area)
{
	int		x;
	int		y;

	y = 0;
	while (area->map[y])
	{
		x = 0;
		while (area->map[y][x])
		{
			if (area->map[y][x] == 'P')
			{
				area->player_x = x;
				area->player_y = y;
			}
			x++;
		}
		y++;
	}
}

void	find_map_area(char *filename, t_area *area)
{
	char	*line;
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
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	area->height = height;
	area->width = first_width;
}

void	count_collectibles(t_area *area)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (area->map[i])
	{
		j = 0;
		while (area->map[i][j])
		{
			if (area->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	area->collect_count = count;
}

t_area	*collect_info(char *filename)
{
	t_area	*area;

	area = (t_area *)malloc(sizeof(t_area));
	if (!area)
		print_message("Error\n Allocation failed\n");
	find_map_area(filename, area);
	map_to_array(filename, area);
	find_player(area);
	count_collectibles(area);
	return (area);
}
