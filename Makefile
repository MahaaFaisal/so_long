CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = so_long
BONUS = so_long_bonus
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a
MLX = mlx/libmlx.a
CFILES = main.c parse_map.c checkers.c window.c keys.c destroyers.c\
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\

BCFILES = bonus/main.c bonus/parse_map.c bonus/checkers.c bonus/init.c\
		bonus/window.c bonus/keys.c bonus/destroyers.c bonus/bonus_utils.c\
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\

all: $(NAME)

$(NAME): $(CFILES) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

$(LIBFT):
	make all -C libft
	
$(MLX):
	make all -C mlx

bonus: $(BCFILES) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(BONUS)

clean:
	make clean -C libft
	make clean -C mlx
	rm -f $(BONUS)

fclean:
	make fclean -C libft
	rm -f $(NAME)
	rm -f $(BONUS)

	make clean -C mlx

re: fclean all
.PHONY: bonus
