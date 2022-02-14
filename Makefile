CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
NAME = so_long
LIBFT = Libft/libft.a

SRC = src/read_map.c \
	src/chk_map.c \
	src/map_error.c \
	src/display_map.c \
	src/hook.c \
	src/player.c \
	src/player_mouvs.c \
	src/game.c \
	src/so_long.c \

SRC_B = src_bonus/read_map_bonus.c \
	src_bonus/chk_map_bonus.c \
	src_bonus/map_error_bonus.c \
	src_bonus/display_map_bonus.c \
	src_bonus/hook_bonus.c \
	src_bonus/player_bonus.c \
	src_bonus/co_animation_bonus.c \
	src_bonus/enemy_animation_bonus.c \
	src_bonus/player_mouvs_bonus.c \
	src_bonus/game_bonus.c \
	src_bonus/so_long_bonus.c \

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make clean -C Libft
	make -C Libft
	$(CC) $(OBJ) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(OBJ_B)
	make clean -C Libft
	make -C Libft
	$(CC) $(OBJ_B) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	make clean -C Libft
	rm -f $(OBJ) $(OBJ_B)

fclean: 	clean
	make fclean -C Libft
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re