/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:24:05 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/09 11:20:11 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_imgs(t_game *game)
{
	game->imgs.bot_left.img = mlx_xpm_file_to_image(game->mlx,
			"tiles/bot_left.xpm", &game->imgs.bot_left.width,
			&game->imgs.bot_left.height);
	check_img(game->imgs.bot_left.img, game);
	game->imgs.bot_right.img = mlx_xpm_file_to_image(game->mlx,
			"tiles/bot_right.xpm", &game->imgs.bot_right.width,
			&game->imgs.bot_right.height);
	check_img(game->imgs.bot_right.img, game);
	game->imgs.top_left.img = mlx_xpm_file_to_image(game->mlx,
			"tiles/top_left.xpm", &game->imgs.top_left.width,
			&game->imgs.top_left.height);
	check_img(game->imgs.top_left.img, game);
	game->imgs.top_right.img = mlx_xpm_file_to_image(game->mlx,
			"tiles/top_right.xpm", &game->imgs.top_right.width,
			&game->imgs.top_right.height);
	check_img(game->imgs.top_right.img, game);
	game->imgs.top_bot.img = mlx_xpm_file_to_image(game->mlx,
			"tiles/top.xpm", &game->imgs.top_bot.width,
			&game->imgs.top_bot.height);
	check_img(game->imgs.top_bot.img, game);
	load_imgs2(game);
}

void	load_imgs2(t_game *game)
{
	game->imgs.left.img = mlx_xpm_file_to_image(game->mlx,
			"tiles/left.xpm", &game->imgs.left.width,
			&game->imgs.left.height);
	check_img(game->imgs.left.img, game);
	game->imgs.right.img = mlx_xpm_file_to_image(game->mlx,
			"tiles/right.xpm", &game->imgs.right.width,
			&game->imgs.right.height);
	check_img(game->imgs.right.img, game);
	game->imgs.collect.img = mlx_xpm_file_to_image(game->mlx,
			"tiles/pum.xpm", &game->imgs.collect.width,
			&game->imgs.collect.height);
	check_img(game->imgs.collect.img, game);
	game->imgs.space.img = mlx_xpm_file_to_image(game->mlx,
			"tiles/space.xpm", &game->imgs.space.width,
			&game->imgs.space.height);
	check_img(game->imgs.space.img, game);
	game->imgs.player.img = mlx_xpm_file_to_image(game->mlx,
			"tiles/player.xpm", &game->imgs.player.width,
			&game->imgs.player.height);
	check_img(game->imgs.player.img, game);
	game->imgs.exit.img = mlx_xpm_file_to_image(game->mlx,
			"tiles/exit.xpm", &game->imgs.exit.width,
			&game->imgs.exit.height);
	check_img(game->imgs.exit.img, game);
}

void	check_img(void	*img, t_game *game)
{
	if (!img)
	{
		free_game(game);
		print_message("Error\nFailed to load an image.\n");
	}
}
