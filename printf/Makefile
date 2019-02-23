# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 13:12:35 by agissing          #+#    #+#              #
#    Updated: 2018/12/16 20:21:54 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#####                              FILES VARS                              #####
################################################################################

NAME = libftprintf.a

INC = includes

SDIR = srcs
_SRC = bitop.c \
		numbers.c \
		ft_printf.c \
		parsing.c \
		utils.c \
		put_double.c \
		basics.c \
		convert.c \
		puthex.c \
		putoct.c \
		putdi.c \
		putuns.c \
		putstring.c \
		putptr.c \
		putpercent.c \
		putbin.c \
		putbase32.c \
		buffer_utils.c \
		putbool.c
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
