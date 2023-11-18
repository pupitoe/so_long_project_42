SOURCES =	main.c \
			sources/ft_check_map.c \
			sources/ft_check_map_content.c \
			sources/ft_check_map_flood_fill.c \
			sources/ft_check_map_rec.c \
			sources/ft_map_item.c \
			sources/ft_check_map_items.c
OBJS = $(SOURCES:.c=.o)
NAME = so_long
CFLAGS = -Wall -Wextra -Werror
CC = gcc

LIBFT=libft/libft.a
LIBMLX = ./MLX42/
LIBS = $(LIBMLX)build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)


all: libmlx $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	gcc $(OBJS) $(LIBS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C libft clean

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)

libft: $(LIBFT)

$(LIBFT):
	@make -C libft

re: fclean all

libmlx:	
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

.PHONY: all clean fclean re
