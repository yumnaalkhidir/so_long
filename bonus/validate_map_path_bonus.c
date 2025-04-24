/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_path_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:23:00 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/08 16:15:53 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill_bonus(t_area *area, char **map, int x, int y)
{
	if (x < 0 || x >= area->width || y < 0 || y >= area->height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F'
		|| map[y][x] == 'E' || map[y][x] == 'S')
		return ;
	map[y][x] = 'F';
	flood_fill_bonus(area, map, x + 1, y);
	flood_fill_bonus(area, map, x - 1, y);
	flood_fill_bonus(area, map, x, y + 1);
	flood_fill_bonus(area, map, x, y - 1);
}

void	check_path_bonus(int x, int y, char **map, t_area *area)
{
	check_path(x, y, map, area);
	if (area->map[y][x] == 'S')
	{
		if ((y > 0 && map[y - 1][x] == 'F' ) || (y > 0 && map[y - 1][x] == '1'))
			return ;
		else if ((y < area->height - 1 && map[y + 1][x] == 'F' ) ||
		(y < area->height - 1 && map[y + 1][x] == '1'))
			return ;
		else if ((x > 0 && map[y][x - 1] == 'F') ||
		(x > 0 && map[y][x - 1] == '1'))
			return ;
		else if ((x < area->width - 1 && map[y][x + 1] == 'F') ||
		(x < area->width - 1 && map[y][x + 1] == '1'))
			return ;
		free_split(map);
		free_split(area->map);
		free(area);
		print_message("1Error\nNo valid path.\n");
	}
}

int	is_valid_map_bonus(t_area *area)
{
	char	**map_copy;
	int		x;
	int		y;

	map_copy = duplicat_map(area->map, area->height);
	if (!map_copy)
		print_message("Error\nMemory allocation failed.\n");
	flood_fill_bonus(area, map_copy, area->player_x, area->player_y);
	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			check_path_bonus(x, y, map_copy, area);
			x++;
		}
		y++;
	}
	free_split(map_copy);
	return (1);
}
