NAME=		fdf

COMPILER=	gcc
FLAGS=		-Werror -Wextra -Wall
INCLUDES=	-I./includes
LIBS=		libft.a -lmlx -framework OpenGL -framework AppKit

SRC_C=		chain_new.c\
			chain_add.c\
			chain_count.c\
			parse_file.c\
			assign_pos.c\
			start_rendering.c\
			img_put_pixel.c\
			img_clear.c\
			vec_init.c\
			pnt_init.c\
			draw.c\
			rotate.c\
			main.c

SRC_O=$(SRC_C:.c=.o)

all: libft.a libft.h libmlx.a $(SRC_O) $(NAME)

libft.a:
	make re -C libft
	cp libft/libft.a .
	make fclean -C libft

libft.h:
	cp libft/includes/libft.h includes

libmlx.a:
	make -C minilibx_macos
	cp minilibx_macos/libmlx.a .
	make clean -C minilibx_macos

%.o: %.c
	$(COMPILER) $(FLAGS) $(INCLUDES) -c $<

$(NAME): $(SRC_C) includes/fdf.h
	$(COMPILER) $(FLAGS) $(INCLUDES) -o $(NAME) $(SRC_O) $(LIBS)

clean:
	rm -rf $(SRC_O)

fclean: clean
	rm -rf fdf libft.a libmlx.a

re: fclean all
