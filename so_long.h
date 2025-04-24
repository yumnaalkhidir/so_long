/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:50:05 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/09 11:23:31 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

# define A 0
# define S 1
# define W 13
# define D 2

typedef struct s_area
{
	int		width;
	int		height;
	char	**map;
	int		player_x;
	int		player_y;
	int		collect_count;
}	t_area;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_tiles
{
	t_img	bot_left;
	t_img	bot_right;
	t_img	top_left;
	t_img	top_right;
	t_img	top_bot;
	t_img	left;
	t_img	right;
	t_img	collect;
	t_img	space;
	t_img	player;
	t_img	exit;	
}	t_tiles;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		moves;
	t_area	*area;
	t_tiles	imgs;
}	t_game;

//            MAP Validation             //
t_area	*check_map(char *filename);

//          Map file extention //
void	check_filename(char *filename);
//          Map walls
void	check_outer_wall(char *line, char *previous, int fd);
void	check_side_walls(char *line, char *previous, int fd);
void	validate_map_walls(char *filename);
//          Map shape
void	check_rectangular(int width, int height, int fd);
void	check_consistent(int width, int first_width, int fd, char *line);
void	validate_map_shape(char *filename);
//          Map elements		
void	check_elements(char *line, int *e, int *c, int *s);
void	validate_map_elements(char *filename);
void	check_elements2(char *line, int *wall, int *space);
void	validate_map_elements2(char	*filename);
void	validate_start_exit(char *filename);
//          Map invalid elements		
void	invalid_elements(char *line, int fd);
void	validate_invalid_elements(char *filename);
//			Map Path			
char	**duplicat_map(char **map, int height);
void	flood_fill(t_area *area, char **map, int x, int y);
void	check_path(int x, int y, char **map, t_area *area);
int		is_valid_map(t_area *area);

//			Initializing Game structure		//
void	map_to_array(char *filename, t_area *area);
void	find_player(t_area *area);
void	find_map_area(char *filename, t_area *area);
void	count_collectibles(t_area *area);
t_area	*collect_info(char *filename);

//		Images
void	allocate_imgs(t_game *game);
void	load_imgs(t_game *game);
void	load_imgs2(t_game *game);
void	check_img(void	*img, t_game *game);

//		FILLING THE MAP
void	fill_bg(t_game *g_mlx);
void	fill_map(t_game *game);
void	fill_corners(t_game *game);
void	fill_sides(t_game *game, int i, int j);
void	fill_wall(t_game *g_mlx, int i, int j);
void	fill_space(t_game *g_mlx, int i, int j);
void	fill_col(t_game *g_mlx, int i, int j);
void	fill_player(t_game *g_mlx, int i, int j);
void	fill_exit(t_game *g_mlx, int i, int j);
void	fill_elements(t_game *game, int i, int j, char c);

//		KEYBOARD INPUT
int		keys(int keycode, t_game *game);
void	check_new_postion(t_game *game, int new_x, int new_y);

//		Printing Messages
void	print_message(char *message);
void	print_moves(int moves);

//			Free func.
void	free_gnl(char *line, int fd);
void	free_split(char **split);
void	free_game(t_game *game);
int		close_win(t_game *game);
void	destroy_imgs(t_game *game);

//		BONUS

#endif