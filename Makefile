
#MLX
INC=%%%%
INCLIB=$(INC)/../lib
LFLAGS = -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm

CC     = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME   = cub3D
FILES  = main.c free_functions.c parse_main.c \
		parse_utils.c parse_check_texture.c parse_check_texture2.c \
		parse_check_texture_help.c check_map_numbers.c\
		check_map_numbers_space.c check_map_numbers_wall.c \
		render_main.c check_map_value.c \
		render_utils.c  render_set_value.c \
		loop_in_render.c vector_operations.c \
		dda_algo.c render_player_rotate.c\
		value_in_render.c render_key_event.c render_player_move.c\
		get_next_line.c get_next_line_utils.c floodfill.c




CFILES = $(addprefix src/, $(FILES))
OFILES = $(addprefix obj/, $(FILES:.c=.o))
DEPS   = inc/cub3D.h inc/libft/libft.h
obj/%.o	: src/%.c $(DEPS)
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@
all: $(NAME)
$(NAME): $(OFILES)
	@make all -C ./inc/libft
	@$(CC) -o $(NAME) $(OFILES) ./inc/libft/libft.a $(LFLAGS)

clean:
	@make clean -C ./inc/libft
	@rm -f $(OFILES)
	@if [ -d "obj" ]; then rmdir obj; fi

fclean: clean
	@rm -f ./inc/libft/libft.a
	@rm -f $(NAME)
re: fclean all
.PHONY:  all clean fclean re
