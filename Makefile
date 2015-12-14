# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/14 14:55:19 by mdos-san          #+#    #+#              #
#    Updated: 2015/12/14 15:47:13 by mdos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		fdf

COMPILER=	gcc
FLAGS=		-Werror -Wextra -Wall
LIBS=		-I./includes -L. -lft # -lmlx -framework OpenGL -framework AppKit

SRC_C=		parse_file.c	main.c

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
	$(COMPILER) $(FLAGS) $(LIBS) -c $<

$(NAME):
	$(COMPILER) $(FLAGS) -o $(NAME) $(SRC_O) $(LIBS)

clean:
	rm -rf $(SRC_O)

fclean: clean
	rm -rf fdf libft.a libmlx.a

re: fclean all
