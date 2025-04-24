/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:36:59 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/08 16:10:18 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		game.area = check_map(av[1]);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, game.area->width * 70,
				game.area->height * 70, "SO_LONG");
		load_imgs(&game);
		game.moves = 0;
		fill_map(&game);
		mlx_hook(game.win, 2, 0, keys, &game);
		mlx_hook(game.win, 17, 0, close_win, &game);
		mlx_loop(game.mlx);
		free_game(&game);
		free_split(game.area->map);
		free(game.area);
	}
	else
		print_message("Error\n");
}
