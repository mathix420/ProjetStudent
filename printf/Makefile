# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 13:12:35 by agissing          #+#    #+#              #
#    Updated: 2018/12/08 17:05:07 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#####                              FILES VARS                              #####
################################################################################

NAME = libftprintf.a

INC = includes

SDIR = srcs
_SRC = bitop.c \
		convert.c \
		ft_printf.c \
		parsing.c \
		utils.c \
		basics/ft_putchar.c \
		basics/ft_isdigit.c
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

OBJ = $(SRC:.c=.o)

################################################################################
#####                           COMPILER OPTIONS                           #####
################################################################################

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC)

################################################################################
#####                            MAKEFILE RULES                            #####
################################################################################

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		@ar -rv $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "Compilation done!"

clean:
		@/bin/rm -f $(OBJ)
		@echo "*.o cleaned!"

fclean: clean
		@/bin/rm -f $(NAME)
		@echo "Cleaning done!"

re: fclean all