/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:44:15 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/09 11:18:38 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_enemy(t_bgame *bgame)
{
	load_imgs(&bgame->game);
	bgame->enemy[0].img = mlx_xpm_file_to_image(bgame->game.mlx,
			"tiles/enemy_1.xpm", &bgame->enemy[0].width,
			&bgame->enemy[0].height);
	check_img(bgame->enemy[0].img, &bgame->game);
	bgame->enemy[1].img = mlx_xpm_file_to_image(bgame->game.mlx,
			"tiles/enemy_2.xpm", &bgame->enemy[1].width,
			&bgame->enemy[1].height);
	check_img(bgame->enemy[1].img, &bgame->game);
	bgame->enemy[2].img = mlx_xpm_file_to_image(bgame->game.mlx,
			"tiles/enemy_3.xpm", &bgame->enemy[2].width,
			&bgame->enemy[2].height);
	check_img(bgame->enemy[2].img, &bgame->game);
}

int	animate_enemy(t_bgame *bgame)
{
	bgame->num++;
	if (bgame->num > 40)
		bgame->num = 0;
	fill_map_b(bgame);
	return (0);
}

void	fill_enemy(t_bgame *bgame, int i, int j)
{
	if (bgame->num <= 10)
		mlx_put_image_to_window(bgame->game.mlx, bgame->game.win,
			bgame->enemy[0].img, j * 70, i * 70);
	else if (bgame->num <= 20)
		mlx_put_image_to_window(bgame->game.mlx, bgame->game.win,
			bgame->enemy[1].img, j * 70, i * 70);
	else if (bgame->num <= 30)
		mlx_put_image_to_window(bgame->game.mlx, bgame->game.win,
			bgame->enemy[2].img, j * 70, i * 70);
	else
		mlx_put_image_to_window(bgame->game.mlx, bgame->game.win,
			bgame->enemy[1].img, j * 70, i * 70);
}

void	fill_bg_bonus(t_bgame *bgame)
{
	int	i;
	int	j;

	if (!bgame->game.imgs.space.img)
	{
		free(&bgame->game);
		print_message("Error\nCan't load background image.\n");
	}
	i = 0;
	while (i < bgame->game.area->height)
	{
		j = 0;
		while (j < bgame->game.area->width)
		{
			mlx_put_image_to_window(bgame->game.mlx, bgame->game.win,
				bgame->game.imgs.space.img, j * 70, i * 70);
			fill_sides(&bgame->game, i, j);
			j++;
		}
		i++;
	}
}

void	fill_map_b(t_bgame *bgame)
{
	int	i;
	int	j;

	fill_bg_bonus(bgame);
	fill_corners(&bgame->game);
	i = 1;
	while (i < bgame->game.area->height - 1)
	{
		j = 1;
		while (j < bgame->game.area->width - 1)
		{
			if (bgame->game.area->map[i][j] == 'S')
				fill_enemy(bgame, i, j);
			else
				fill_elements(&bgame->game, i, j, bgame->game.area->map[i][j]);
			j++;
		}
		i++;
	}
	print_moves_onscreen(&bgame->game);
}
