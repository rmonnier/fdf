# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 10:17:46 by rmonnier          #+#    #+#              #
#    Updated: 2017/01/04 18:04:58 by rmonnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		fdf
SRCS_NAME		=	connect_dots.c\
						compute_screen_view.c\
						draw_image.c\
						display_map.c\
						fdf_error.c\
						local_endian.c\
						main.c\
						parse_map.c
SRCS_PATH		=		srcs/
SRCS			=		$(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ_NAME		=		$(SRCS_NAME:.c=.o)
OBJ_PATH		=		obj/
OBJ				=		$(addprefix $(OBJ_PATH), $(OBJ_NAME))
FLAGS			=		-Wall -Werror -Wextra
INC				=		-I./includes/ -I./libft/
LIB				=		-Lminilibx -lmlx -framework OpenGL -framework AppKit \
						-Llibft -lft


.PHONY: all, clean, fclean, re

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx/
	gcc $(FLAGS) -o $(NAME) $(SRCS) $(INC) $(LIB)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	gcc -c $(FLAGS) $< -o $@ $(INC)

clean:
	make -C minilibx/ clean
	make -C libft/ fclean
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
