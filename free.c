/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:23:27 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/08 16:13:22 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_gnl(char *line, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	destroy_imgs(t_game *game)
{
	if (game->imgs.bot_left.img)
		mlx_destroy_image(game->mlx, game->imgs.bot_left.img);
	if (game->imgs.bot_right.img)
		mlx_destroy_image(game->mlx, game->imgs.bot_right.img);
	if (game->imgs.top_left.img)
		mlx_destroy_image(game->mlx, game->imgs.top_left.img);
	if (game->imgs.top_right.img)
		mlx_destroy_image(game->mlx, game->imgs.top_right.img);
	if (game->imgs.top_bot.img)
		mlx_destroy_image(game->mlx, game->imgs.top_bot.img);
	if (game->imgs.left.img)
		mlx_destroy_image(game->mlx, game->imgs.left.img);
	if (game->imgs.right.img)
		mlx_destroy_image(game->mlx, game->imgs.right.img);
	if (game->imgs.collect.img)
		mlx_destroy_image(game->mlx, game->imgs.collect.img);
	if (game->imgs.space.img)
		mlx_destroy_image(game->mlx, game->imgs.space.img);
	if (game->imgs.player.img)
		mlx_destroy_image(game->mlx, game->imgs.player.img);
	if (game->imgs.exit.img)
		mlx_destroy_image(game->mlx, game->imgs.exit.img);
}

void	free_game(t_game *game)
{
	destroy_imgs(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
	if (game->area)
	{
		free_split(game->area->map);
		free(game->area);
	}
}

int	close_win(t_game *game)
{
	free_game(game);
	exit(0);
}
