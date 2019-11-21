NAME = fdf
SRC = SRC/main.c SRC/ft_read.c SRC/get_next_line.c SRC/ft_brezenham.c
LIBFT_DIR = libft
LIBS = libft/libft.a
OBJ = $(SRC:.c=.o)
HEADERS = ./SRC/fdf.h
all:
	@$(MAKE) -C $(LIBFT_DIR)
	@gcc -o $(NAME) $(SRC) $(LIBS) -lmlx -framework OpenGL -framework AppKit
clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -f $(OBJ)
fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
re: fclean all