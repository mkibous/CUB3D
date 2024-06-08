NAME = cub3D
SRC = main.c ./execute/execute.c ./Parsing/parsing.c ./Get_next_line/get_next_line.c \
	./Get_next_line/get_next_line_utils.c ./parsing/first_element.c ./parsing/utils_parsing.c \
	./parsing/utils_parsing_2.c ./parsing/check_valid_elem.c ./parsing/check_map.c ./parsing/utils_parsing_3.c \
	./parsing/check_element_f_c.c ./parsing/check_closed.c ./execute/textures.c ./parsing/utils_check.c
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
HEADER = cub3d.h
LIBFT = libft/libft.a
OBJ = $(SRC:.c=.o)
CC = cc
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
all: make_libft $(NAME)

make_libft:
	@cd libft && make

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

push:
	@read -p "Enter commit message: " commit_message; \
	git add .; \
	git commit -m "$$commit_message"; \
	git push;

pull:
	@git stash
	@git pull
	@git stash pop

.PHONY: clean make_libft