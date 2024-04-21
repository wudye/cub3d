
NAME = cub3D

INCL = includes

LIB_DIR = libft

LIB = $(LIB_DIR)/libft.a

FILES =	main.c free_functions.c parse_main.c \
		parse_utils.c parse_check_texture.c \
		parse_check_texture_help.c check_map_numbers.c\
		check_map_numbers_space.c check_map_numbers_wall.c \
		render_mlx_main.c \
		get_next_line.c get_next_line_utils.c 

CFLILES = ${addprefix srcs/, ${FILES}}		
OFILES = $(addprefix obj/,$(FILES:.c=.o))

CFLAGS = -g -Wall -Wextra -Werror -I $(INCL) -I $(I_MLX) -I $(LIB_DIR)

CC = cc

I_MLX = minilibx_linux

LFLAGS = -lXext -lX11 -lm

MLX_NAME = $(I_MLX)/libmlx.a

RM = rm -rf

HEADER = $(INCL)/cub3D.h


obj/%.o: srcs/%.c $(HEADER)
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OFILES)
	@make -C $(LIB_DIR)
	@make -C $(I_MLX)
	$(CC) $(CFLAGS) $(OFILES) $(LIB) $(MLX_NAME) $(LFLAGS) -o $(NAME)

clean:
	make clean -C $(LIB_DIR)
	$(RM) $(OFILES)

fclean:	clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re: fclean all
.PHONY: all bonus clean fclean re

