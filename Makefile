CC:= cc
CCFLAGS:= -Wall -Werror -Wextra

MLXFLAG:= -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT:= libft/libft.a
GNL:= get_next_line/gnl.a
MLX:= mlx/libmlx.a

FILES:= main.c fill_map.c free.c images.c keys.c print_messages.c struct_info.c \
	validate_map_elements.c validate_map_invalid_elements.c validate_map_path.c validate_map_shape.c validate_map_walls.c validate_map.c
BONUS:= bonus/b_main.c fill_map.c free.c images.c keys.c print_messages.c struct_info.c \
	bonus/validate_map_elements_bonus.c bonus/validate_map_invalid_elements_bonus.c bonus/validate_map_path_bonus.c validate_map_shape.c \
	validate_map_walls.c bonus/validate_map_bonus.c bonus/enemy_pos.c bonus/load_bonus.c validate_map_elements.c validate_map_invalid_elements.c validate_map_path.c validate_map.c

HEADER:= so_long.h
BHEADER:= bonus/so_long_bonus.h
NAME:= so_long
BNAME:= so_long_bonus
OFILES:= $(FILES:.c=.o)
OBONUS:= $(BONUS:.c=.o)

all: $(LIBFT) $(GNL) $(MLX) $(NAME)

%.o: %.c $(HEADER) $(BHEADER)
	$(CC) $(CCFLAGS) -I$(MLX) -c $< -o $@

$(LIBFT):
	make -C libft
$(GNL):
	make -C get_next_line
$(MLX):
	make -C mlx

$(NAME): $(OFILES)
	$(CC) $(CCFLAGS) $(MLXFLAG) $(OFILES) $(LIBFT) $(GNL) $(MLX) -o $(NAME)

bonus: $(OBONUS)
	make -C libft
	make -C get_next_line
	$(CC) $(CCFLAGS) $(MLXFLAG) $(OBONUS) $(LIBFT) $(GNL) $(MLX) -o $(BNAME)
clean:
	make clean -C libft
	make clean -C get_next_line
	# make clean -C mlx
	rm -f $(OFILES) $(OBONUS)

fclean: clean
	make fclean -C libft
	make fclean -C get_next_line
	# make clean -C mlx
	rm -f $(NAME) $(BNAME)

re: fclean all
.PHONY: all clean fclean re
