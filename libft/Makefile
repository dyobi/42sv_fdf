# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kilkim <kilkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/01 21:01:00 by kilkim            #+#    #+#              #
#    Updated: 2019/09/05 18:44:47 by kilkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIB_D = srcs
PTF_D = ft_printf
GNL_D = get_next_line
INC_D = includes/
OBJ_D = obj

# compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I $(INC_D)

CHECK = \033[0;33m\xE2\x9C\x94\033[0m
CYAN  = \x1B[36m
GREEN = \x1B[1;32m
YELLO = \x1B[1;4;33m
EOC   = \033[0m

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_D)
	@echo ""
	@echo "$(CYAN)  [     ] Make object files from $(GREEN)libft $(CYAN)...$(EOC)\c"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $(LIB_D)/*.c
	@echo "\r$(CYAN)  [  $(CHECK)$(CYAN)  ] Make object files form $(YELLO)libft$(EOC)$(CYAN) ...$(EOC)"
	@echo ""
	@echo ""
	@echo "$(CYAN)  [     ] Make object files from $(GREEN)ft_printf $(CYAN)...$(EOC)\c"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $(PTF_D)/*.c
	@echo "\r$(CYAN)  [  $(CHECK)$(CYAN)  ] Make object files form $(YELLO)ft_printf$(EOC)$(CYAN) ...$(EOC)"
	@echo ""
	@echo ""
	@echo "$(CYAN)  [     ] Make object files from $(GREEN)get_next_line $(CYAN)...$(EOC)\c"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $(GNL_D)/*.c
	@echo "\r$(CYAN)  [  $(CHECK)$(CYAN)  ] Make object files form $(YELLO)get_next_line$(EOC)$(CYAN) ...$(EOC)"
	@echo ""
	@echo ""
	@mv *.o $(OBJ_D)
	@echo "$(CYAN)  [     ] Make libft.a [ $(GREEN) 0  / 100 %$(CYAN) ] : )$(EOC)\c"

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ_D)/*.o
	@ranlib $(NAME)
	@echo "\r$(CYAN)  [  $(CHECK)$(CYAN)  ] Make libft.a [ $(YELLO)100 / 100%$(EOC)$(CYAN)  ] : )$(EOC)"
	@echo ""

clean:
	@echo ""
	@echo "$(CYAN)  [     ] Makefile has been $(YELLO)cleaned$(EOC)$(CYAN) : )$(EOC)\c"
	@rm -rf $(OBJ_D)
	@echo "\r$(CYAN)  [  $(CHECK)$(EOC)"
	@echo ""

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
