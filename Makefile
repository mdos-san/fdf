# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 17:35:31 by mdos-san          #+#    #+#              #
#    Updated: 2016/01/23 12:10:27 by mdos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		fdf

COMPILER=	gcc
FLAGS=		-Werror -Wextra -Wall -g3 -fsanitize=address
INCLUDES=	-I./includes
LIBS=		libft.a -lmlx -framework OpenGL -framework AppKit -lm
MLX_PATH	= libs/minilibx_macos

OS			= $(shell uname)

ifeq ($(OS), Linux)
MLX_PATH	= libs/minilibx_linux
LIBS		= libft.a libmlx.a -lX11 -lXext -lm
endif

SRC_C=\
			chain_new.c\
			chain_min.c\
			chain_max.c\
			chain_zoom.c\
			start_rendering.c\
			img_put_pixel.c\
			img_putline.c\
			img_clear.c\
			pnt_new.c\
			pnt_get.c\
			pnt_init.c\
			pnt_translate.c\
			draw.c\
			get_pnt.c\
			get_pnt_color.c\
			rotate.c\
			move_position.c\
			grad_new.c\
			get_grad.c\
			grad_apply.c\
			key_event.c\
			expose_event.c\
			vec_new.c\
			vec_del.c\
			vec_get.c\
			vec_rotate.c\
			vec_draw.c\
			vec_multiply.c\
			vec_add.c\
			repere_new.c\
			repere_rotate.c\
			parse.c\
			main.c

SRC_O=$(SRC_C:.c=.o)

all: objects libft.a includes/libft.h libmlx.a $(SRC_O:%=objects/%) $(NAME)

objects:
	@mkdir objects

libft.a:
	@echo "Compling libft.a"
	@make re -C libs/libft
	@cp libs/libft/libft.a .
	@make fclean -C libs/libft
	@echo "Done!"

libft.h:
	@cp libs/libft/includes/libft.h includes

libmlx.a:
	@echo "Compiling libmlx.a"
	@make -C $(MLX_PATH)
	@cp $(MLX_PATH)/libmlx.a .
	@make clean -C $(MLX_PATH)
	@echo "Done!"

objects/%.o: srcs/%.c
	@echo "Compling $<"
	@$(COMPILER) $(FLAGS) $(INCLUDES) -c $<
	@mv $(notdir $@) objects

$(NAME): $(SRC_C:%=srcs/%) includes/fdf.h
	@$(COMPILER) $(FLAGS) $(INCLUDES) -o $(NAME) $(SRC_O:%=objects/%) $(LIBS)
	@echo "Fdf has been created!"

clean:
	rm -rf objects

fclean: clean
	rm -rf fdf libft.a libmlx.a
	rm -rf libs/minilibx_linux/libmlx_Linux.a

re: fclean all
