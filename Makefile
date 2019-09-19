# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kilkim <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 00:50:47 by kilkim            #+#    #+#              #
#    Updated: 2019/09/08 04:05:48 by kilkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# src / obj
SRC	= main.c init_1.c  init_2.c free.c proj.c color.c \
	  draw.c function.c control_1.c control_2.c

OBJ = $(addprefix $(PATH_OBJ),$(SRC:.c=.o))

# compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# mlx library
MLX = ./minilibx/
MLX_LIB = $(addprefix $(MLX),mlx.a)
MLX_INC = -I ./minilibx
MLX_LNK = -L ./minilibx -l mlx -framework OpenGL -framework AppKit

# libft library
FT = ./libft/
FT_LIB = $(addprefix $(FT),libft.a)
FT_INC = -I ./libft
FT_LNK = -L ./libft -l ft

# directory
PATH_SRC = ./src/
PATH_INC = ./include/
PATH_OBJ = ./obj/

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	@mkdir -p $(PATH_OBJ)

$(PATH_OBJ)%.o:$(PATH_SRC)%.c
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(PATH_INC) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	@rm -rf $(PATH_OBJ)
	@make -C $(FT) clean
	@make -C $(MLX) clean

fclean:
	@rm -rf $(NAME)
	@rm -rf $(PATH_OBJ)
	@make -C $(MLX) clean
	@make -C $(FT) fclean

re: fclean all
