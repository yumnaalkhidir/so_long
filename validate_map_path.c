/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:23:00 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/08 15:01:58 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**duplicat_map(char **map, int height)
{
	char	**cpy_map;
	int		i;

	i = 0;
	cpy_map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!cpy_map)
	{
		return (NULL);
	}
	while (map[i])
	{
		cpy_map[i] = ft_strdup(map[i]);
		if (!cpy_map[i])
		{
			while (i--)
				free(cpy_map[i]);
			free(cpy_map);
			return (NULL);
		}
		i++;
	}
	cpy_map[i] = NULL;
	return (cpy_map);
}

void	flood_fill(t_area *area, char **map, int x, int y)
{
	if (x < 0 || x >= area->width || y < 0 || y >= area->height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'E')
		return ;
	map[y][x] = 'F';
	flood_fill(area, map, x + 1, y);
	flood_fill(area, map, x - 1, y);
	flood_fill(area, map, x, y + 1);
	flood_fill(area, map, x, y - 1);
}

void	check_path(int x, int y, char **map, t_area *area)
{
	if (area->map[y][x] == 'C' && map[y][x] != 'F')
	{
		free_split(map);
		free_split(area->map);
		free(area);
		print_message("Error\nNo valid path.\n");
	}
	if (area->map[y][x] == 'E')
	{
		if (y > 0 && map[y - 1][x] == 'F')
			return ;
		else if (y < area->height - 1 && map[y + 1][x] == 'F')
			return ;
		else if (x > 0 && map[y][x - 1] == 'F' )
			return ;
		else if (x < area->width - 1 && map[y][x + 1] == 'F')
			return ;
		free_split(map);
		free_split(area->map);
		free(area);
		print_message("Error\nNo valid path.\n");
	}
}

int	is_valid_map(t_area *area)
{
	char	**map_copy;
	int		x;
	int		y;

	map_copy = duplicat_map(area->map, area->height);
	if (!map_copy)
		print_message("Error\nMemory allocation failed.\n");
	flood_fill(area, map_copy, area->player_x, area->player_y);
	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			check_path(x, y, map_copy, area);
			x++;
		}
		y++;
	}
	free_split(map_copy);
	return (1);
}
