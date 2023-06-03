NAME = so_long

NAMEBONUS = so_long_bonus

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = so_long.c get_next_line.c get_next_line_utils.c ft_split.c valid_map.c help.c errors.c mouvement.c errors2.c mlx.c

SRCBONUS = so_long_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c ft_split_bonus.c valid_map_bonus.c help_bonus.c errors_bonus.c mouvement_bonus.c errors2_bonus.c mlx_bonus.c

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(FLAGS) $(SRC) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	@rm -rf $(NAME) $(NAMEBONUS)
fclean : clean

re : fclean all

bonus: $(SRCBONUS)
	$(CC) $(FLAGS) $(SRCBONUS) -lmlx -framework OpenGL -framework AppKit -o $(NAMEBONUS)
