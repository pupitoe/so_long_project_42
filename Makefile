SOURCES =	main.c \
			sources/ft_pos.c \
			sources/ft_check_map.c \
			sources/ft_check_map_content.c \
			sources/ft_check_map_flood_fill.c \
			sources/ft_check_map_rec.c \
			sources/ft_map_content.c \
			sources/ft_check_map_items.c \
			sources/ft_check_map_path.c \
			sources/ft_error.c \
			sources/ft_antity.c\
			sources/ft_player.c \
			sources/ft_graphique.c \
			sources/ft_graphique_lst_0.c \
			sources/ft_graphique_lst_1.c \
			sources/ft_graphique_map.c
OBJS = $(SOURCES:.c=.o)
NAME = so_long
CFLAGS = -Wall -Wextra -Werror -g3
CC = gcc
HEADERS =	headers/ft_check_map.h \
			headers/ft_error.h \
			headers/ft_player.h \
			headers/ft_pos.h \
			headers/ft_map_content.h	
LIBFT=libft/libft.a
LIBMLX = ./MLX42
LIBMLXCOMPILE = $(LIBMLX)/build/libmlx42.a
LIBS = $(LIBMLXCOMPILE) -ldl -lglfw -pthread -lm $(LIBFT)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(HEADERS) $(LIBMLXCOMPILE)
	gcc $(OBJS) $(LIBS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@make -C libft clean
	@rm -rf $(LIBMLX)/build

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)

libft: $(LIBFT)

$(LIBFT):
	@make -C libft

re: fclean all

$(LIBMLXCOMPILE):
	@make libmlx

libmlx:	
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

.PHONY: all clean fclean re