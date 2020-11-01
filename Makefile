NAME = fdf

SRC = fdf.c \
	src/ft_init_window.c \
	src/ft_key_win.c \
	src/ft_discover_map.c \
	src/ft_catch_order.c \
	src/ft_set_constants.c \
	src/ft_calc_digits.c \
	src/ft_draw_map.c \
	src/ft_draw.c \
	src/ft_plot_line.c \
	src/ft_put_pixel.c \
	src/ft_transform.c \
	src/ft_camera.c \
	src/ft_fill_map.c \
	src/ft_rotate.c \
	src/ft_mouse.c \
	src/ft_color.c \
	src/ft_init.c \
	gnl/get_next_line.c

INCLUDES = /usr/local/include

LIBOBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra
GLFLAGS = -lm -lmlx -framework OpenGL -framework AppKit

$(NAME): $(LIBOBJ)
		make -C ./libft
		gcc $(CFLAGS) $(LIBOBJ) -L./libft -I $(INCLUDES) $(GLFLAGS) -lft -o $(NAME)
%.o:%.c fdf.h keys.h
		gcc -MD -c $<  -o $@

all: $(NAME)


clean:
	make -C ./libft clean
	-rm -rf $(LIBOBJ)
	-rm -f src/*.d

fclean: clean
	make -C ./libft fclean
	-rm -f $(NAME)
	-rm -f src/*.d

re: fclean all
