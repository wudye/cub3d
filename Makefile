
NAME = cub3D

INCL = includes

O_DIR =	obj

LIB_DIR = libft

LIB = $(LIB_DIR)/libft.a

S_DIR =	srcs

SRCS =	srcs/main.c srcs/free_functions.c srcs/parse_main.c \
		srcs/parse_utils.c srcs/parse_check_texture.c \
		srcs/get_next_line.c srcs/get_next_line_utils.c 
		
# $(S_DIR)/parse_data.c			$(S_DIR)/utilis.c\
# 					$(S_DIR)/check_data.c			$(S_DIR)/check_texture.c\
# 					$(S_DIR)/executing.c			$(S_DIR)/check_zeros_and_player.c\
# 					$(S_DIR)/free_memory.c			$(S_DIR)/color_floor_and_ceiling_checker.c\
# 					$(S_DIR)/init_structs.c			$(S_DIR)/minilibx_functions.c\
# 					$(S_DIR)/raycast.c				$(S_DIR)/init_structs_2.c\
# 					$(S_DIR)/work_with_textures.c

OBJS = $(addprefix $(O_DIR)/,$(SRCS:.c=.o))

CFLAGS = -g -Wall -Wextra -Werror -I $(INCL) -I $(I_MLX) -I $(LIB_DIR)

CC = cc

I_MLX = minilibx_linux

LFLAGS = -lXext -lX11 -lm

MLX_NAME = $(I_MLX)/libmlx.a

RM = rm -rf

HEADER = $(INCL)/cub3D.h


$(O_DIR)/%.o: %.c $(HEADER)
	mkdir -p $(O_DIR)
	mkdir -p $(O_DIR)/$(S_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_DIR)
	@make -C $(I_MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX_NAME) $(LFLAGS) -o $(NAME)

clean:
	make clean -C $(LIB_DIR)
	$(RM) $(O_DIR)

fclean:	clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re: fclean all
.PHONY: all bonus clean fclean re

