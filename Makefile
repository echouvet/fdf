# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echouvet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 14:37:04 by echouvet          #+#    #+#              #
#    Updated: 2018/01/16 17:24:05 by tgoldber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIB = ./libft
LIBPATH = libft/libft.a

SRC = main.c \
basics.c \
parcer.c \
print.c \
translation.c \
color.c \
brasenham.c \
brasenham2.c \
brasenham3.c \
rotation.c \
z.c \
zoom_and_red.c \

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
EXT = -lmlx -framework OpenGL -framework Appkit

all: $(NAME)
	
$(NAME): $(OBJ)
	@make -C $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBPATH) $(EXT)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIB)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIB)

norme:
	norminette $(SRC)

normeerrors:
	norminette $(SRC) | grep -b1 Error

debug:
	$(CC) $(CFLAGS) -g3 -fsanitize=address -o $(NAME) $(OBJ) $(LIBPATH) $(EXT)

re: fclean all

.PHONY: all, re, clean, fclean
