NAME = so_long

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = so_long.c get_next_line.c get_next_line_utils.c ft_split.c valid_map.c help.c errors.c mouvement.c 

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(FLAGS) $(SRC) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	@rm -rf $(NAME)
fclean : clean

re : fclean all