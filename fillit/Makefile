# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 11:04:35 by agissing          #+#    #+#              #
#    Updated: 2018/11/27 19:08:46 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#####                              FILES VARS                              #####
################################################################################

NAME = fillit

SDIR = .
_SRC =	main.c \
		basics.c \
		stockage.c \
		solver.c \
		map.c	\
		read.c	\
		display.c \
		bits.c
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

OBJ = $(SRC:.c=.o)

################################################################################
#####                           COMPILER OPTIONS                           #####
################################################################################

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft/
OPTS = -o $(NAME) -I. -Ilibft/ libft/libft.a

################################################################################
#####                            MAKEFILE RULES                            #####
################################################################################

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):	$(OBJ)
		@make -C libft/
		@$(CC) $(OBJ) $(OPTS)
		@echo "Compilation done!"

clean:
		@make -C libft/ clean
		@/bin/rm -f $(OBJ)
		@echo "*.o cleaned!"

fclean: clean
		@make -C libft/ fclean
		@/bin/rm -f $(NAME)
		@echo "Cleaning done!"

re: fclean all
		@make -C libft/ re
