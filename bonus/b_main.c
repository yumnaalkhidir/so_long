/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:59:07 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/09 11:19:02 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_bgame	bgame;

	if (ac == 2)
	{
		bgame.game.area = check_map_bonus(av[1]);
		bgame.game.mlx = mlx_init();
		bgame.game.win = mlx_new_window(bgame.game.mlx,
				bgame.game.area->width * 70, bgame.game.area->height * 70,
				"SO_LONG_BONUS");
		load_enemy(&bgame);
		bgame.game.moves = 0;
		bgame.num = 0;
		fill_map_b(&bgame);
		mlx_hook(bgame.game.win, 2, 0, keys_b, &bgame);
		mlx_hook(bgame.game.win, 17, 0, close_win, &bgame.game);
		mlx_loop_hook(bgame.game.mlx, animate_enemy, &bgame);
		mlx_loop(bgame.game.mlx);
		free_game(&bgame.game);
		free_split(bgame.game.area->map);
		free(bgame.game.area);
	}
	else
		print_message("Error\n");
}
