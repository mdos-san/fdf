# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 17:35:31 by mdos-san          #+#    #+#              #
#    Updated: 2015/12/18 17:49:55 by mdos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		fdf

COMPILER=	gcc
FLAGS=		-Werror -Wextra -Wall
INCLUDES=	-I./includes
LIBS2=		libft.a libmlx.a -lX11 -lXext -lm
LIBS=		libft.a  -lmlx -framework OpenGL -framework AppKit -lm

SRC_C=\
			chain_new.c\
			start_rendering.c\
			img_put_pixel.c\
			img_clear.c\
			vec_init.c\
			pnt_init.c\
			pnt_new.c\
			draw.c\
			get_pnt.c\
			main.c

SRC_O=$(SRC_C:.c=.o)

all: libft.a includes/libft.h libmlx.a $(SRC_O) $(NAME)

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

ubuntu: $(SRC_O) $(SRC_C) libft.a includes/libft.h includes/fdf.h
	$(COMPILER) $(FLAGS) $(INCLUDES) -o $(NAME) $(SRC_O) $(LIBS2)

$(NAME): $(SRC_C) includes/fdf.h
	$(COMPILER) $(FLAGS) $(INCLUDES) -o $(NAME) $(SRC_O) $(LIBS)

clean:
	rm -rf $(SRC_O)

fclean: clean
	rm -rf fdf libft.a libmlx.a

re: fclean all
