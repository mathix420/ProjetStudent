# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 17:10:19 by agissing          #+#    #+#              #
#    Updated: 2019/02/11 19:30:00 by acompagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# ***                            MF-GEN MAKEFILE                           *** #
# **************************************************************************** #

################################################################################
#####                              FILES VARS                              #####
################################################################################

LEMIN = lem-in

DIR_SRCS0 = srcs
_SRCS0 = check.c \
			exit.c \
			init.c \
			link.c \
			lst.c \
			main.c \
			print.c \
			sort_input.c \
			start_end.c \
			delete_cpy.c \
			way.c  \
			free.c \
			solving.c \
			sort_output.c

LEMIN_SRC = $(patsubst %,$(DIR_SRCS0)/%,$(_SRCS0))

LEMIN_OBJ = $(patsubst %,obj/%,$(_SRCS0:.c=.o))
LIBFT = libft/libft.a

################################################################################
#####                           COMPILER OPTIONS                           #####
################################################################################

CC = gcc
FLAGS = -Wall -Wextra -Werror

################################################################################
#####                            MAKEFILE RULES                            #####
################################################################################

.PHONY : all clean fclean re

all : $(LEMIN)

$(LIBFT) :
	@make -C libft

$(LEMIN_OBJ) : obj%.o : $(DIR_SRCS0)%.c
	@$(CC) $(FLAGS) -c $< -o $@ -Iinc -Ilibft -g3
	@printf "\e[2K \e[32m[CC]\e[0m %-15s\r" "$<"

$(LEMIN) : $(LEMIN_OBJ) $(LIBFT)
	@$(CC) $(FLAGS) $(LEMIN_OBJ) -o $@ -Iinc -Ilibft -Llibft -lft
	@printf "\e[2K\e[94m[PRG]\e[0m $(LEMIN) done !\n"

fsanitize : $(LEMIN_OBJ) $(LIBFT)
	@$(CC) $(FLAGS) $(LEMIN_OBJ) -o $(LEMIN) -Iinc -Ilibft -Llibft -lft -fsanitize=address -g3
	@printf "\e[2K\e[94m[PRG]\e[0m $(LEMIN) done !\n"

clean :
	@/bin/rm -f $(LEMIN_OBJ)
	@make clean -C libft
	@echo "\033[33m[PRG]\033[0m Cleaning done"

fclean :
	@/bin/rm -f $(LEMIN_OBJ)
	@/bin/rm -f $(LEMIN)
	@make fclean -C libft
	@echo "\033[33m[PRG]\033[0m Cleaning done"

re : fclean all
