# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 17:10:19 by agissing          #+#    #+#              #
#    Updated: 2019/02/22 18:09:57 by acompagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# ***                            MF-GEN MAKEFILE                           *** #
# **************************************************************************** #

################################################################################
#####                              FILES VARS                              #####
################################################################################

LEMIN = lem-in

DIR_SRCS0 = srcs
_SRCS0 = 	main.c \
			init.c \
			start_end.c \
			link.c \
			free.c \
			check.c \
			exit.c \
			lst.c \
			bfs.c \
			sort_input.c \
			tree.c \
			resolve.c \
			queue.c \
			print.c

LEMIN_SRC = $(patsubst %,$(DIR_SRCS0)/%,$(_SRCS0))

DIR_OBJ = obj
LEMIN_OBJ = $(patsubst %,$(DIR_OBJ)/%,$(_SRCS0:.c=.o))
LIBFT = libft/libft.a

################################################################################
#####                           COMPILER OPTIONS                           #####
################################################################################

CC = gcc
FLAGS = -Wall -Wextra -Werror -g3

################################################################################
#####                            MAKEFILE RULES                            #####
################################################################################

.PHONY : all clean fclean re

all : $(LEMIN)

$(LIBFT) :
	@make -C libft

$(DIR_OBJ) :
	@mkdir -p $@
	@printf "\e[2K\e[94m[OBJ]\e[0m Directory created!\n"

$(LEMIN_OBJ) : obj%.o : $(DIR_SRCS0)%.c
	@$(CC) $(FLAGS) -c $< -o $@ -Iinc -Ilibft
	@printf "\e[2K \e[32m[CC]\e[0m %-15s\r" "$<"

$(LEMIN) : $(DIR_OBJ) $(LEMIN_OBJ) $(LIBFT)
	@$(CC) $(FLAGS) $(LEMIN_OBJ) -o $@ -Iinc -Ilibft -Llibft -lft
	@printf "\e[2K\e[94m[PRG]\e[0m $(LEMIN) done!\n"

clean :
	@/bin/rm -rf $(DIR_OBJ)
	@make clean -C libft
	@echo "\033[33m[PRG]\033[0m Cleaning done"

fclean :
	@/bin/rm -rf $(DIR_OBJ)
	@/bin/rm -f $(LEMIN)
	@make fclean -C libft
	@echo "\033[33m[PRG]\033[0m Cleaning done"

re : fclean all
