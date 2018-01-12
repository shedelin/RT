#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/30 15:52:06 by caupetit          #+#    #+#              #
#    Updated: 2014/03/27 19:45:16 by tmielcza         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: clean fclean all re

NAME = RT
SRC = main.c \
	vect.c \
    mlx.c \
    scene.c \
    obj.c \
	calc.c \
	cam.c \
	ray.c \
	sphere.c \
	plane.c \
	cylinder.c \
	cone.c \
	ellipsoid.c \
	draw.c \
	light.c \
	rotation.c \
	lex_lst.c \
	lex_automaton.c \
	lexer.c \
	diffuse.c \
	specular.c \
	reflection.c \
	materials.c \
	color.c \
	lex_lst.c \
	lex_automaton.c \
	scene_aut_cam.c \
	scene_aut_spot.c \
	scene_aut_obj.c \
	scene_aut_otype.c \
	scene_aut_mat.c \
	aut_sphere.c \
	aut_plane.c \
	aut_cylinder.c \
	aut_cone.c \
	aut_ellips.c \
	is.c \
	lexer.c \
	ft_interface.c \
	ft_interface2.c \
	ft_del_env.c

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror -O3

FLAGS += -pedantic -Wstrict-prototypes -Wunused \
		-Wmissing-declarations -Wmissing-prototypes -Wshadow \
		-Winit-self

LIBSMLX = -lmlx -lXext -lX11
LIBPATHMLX = -L/opt/X11/lib/
CC = cc

all: lib $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $^ -o $@ -L./libft/ -lft $(LIBPATHMLX) $(LIBSMLX)
	@echo "==> Program [$@] compiled"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -I libft/includes
	@echo "==> [$<] compiled"

lib:
	@make -C libft all

clean:
	@rm -f $(OBJ)
	@make -C libft clean
	@echo "==> Objects removed"
fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@echo "==> Program [$(NAME)] removed"

re: fclean all
