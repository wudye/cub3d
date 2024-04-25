#MLX
INC=%%%%
INCLIB=$(INC)/../lib
LFLAGS = -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm

CC     = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME   = cub3d
FILES  = main.c \
		init_rays.c \
		math.c \
		render.c \
		render_utils.c \
		movement.c \
		utils.c

CFILES = $(addprefix src/, $(FILES))
OFILES = $(addprefix obj/, $(FILES:.c=.o))
DEPS   = inc/cub3d.h inc/libft/libft.h
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
