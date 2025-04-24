/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:01:46 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/08 13:42:44 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keys(int keycode, t_game *game)
{
	int	new_px;
	int	new_py;

	new_px = game->area->player_x;
	new_py = game->area->player_y;
	if (keycode == 53)
	{
		free_game(game);
		exit (0);
	}
	else if (keycode == A)
		new_px--;
	else if (keycode == D)
		new_px++;
	else if (keycode == S)
		new_py++;
	else if (keycode == W)
		new_py--;
	else
		return (-1);
	check_new_postion(game, new_px, new_py);
	if (game->area->map[new_py][new_px] != '1')
		print_moves(game->moves);
	return (0);
}

void	check_new_postion(t_game *game, int new_x, int new_y)
{
	if (game->area->map[new_y][new_x] == 'E')
	{
		if (game->area->collect_count == 0)
		{
			write(1, "You Win\n", 9);
			free_game(game);
			exit(0);
		}
		return ;
	}
	if (game->area->map[new_y][new_x] == '1')
		return ;
	if (game->area->map[new_y][new_x] == 'C')
		game->area->collect_count--;
	game->area->map[game->area->player_y][game->area->player_x] = '0';
	game->area->map[new_y][new_x] = 'P';
	game->area->player_x = new_x;
	game->area->player_y = new_y;
	fill_map(game);
	game->moves++;
}
