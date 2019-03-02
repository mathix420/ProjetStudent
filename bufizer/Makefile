# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/02 19:06:14 by agissing          #+#    #+#              #
#    Updated: 2019/03/02 20:08:45 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# ***                            MF-GEN MAKEFILE                           *** #
# **************************************************************************** #

################################################################################
#####                              FILES VARS                              #####
################################################################################

BUFFIZER = buffizer

DIR_SRCS0 = srcs
_SRCS0 = bufizer.c \
		put_bin.c \
		put_char.c \
		put_color.c \
		put_digit.c \
		put_hex.c \
		put_oct.c \
		put_str.c \
		manage_buf.c
BUFFIZER_SRC = $(patsubst %,$(DIR_SRCS0)/%,$(_SRCS0))

BUFFIZER_OBJ = $(BUFFIZER_SRC:.c=.o)

################################################################################
#####                           COMPILER OPTIONS                           #####
################################################################################

CC = gcc
FLAGS = -Wall -Wextra -Werror

################################################################################
#####                            MAKEFILE RULES                            #####
################################################################################

.PHONY : all clean fclean re

all : $(BUFFIZER)

$(BUFFIZER_OBJ) : %.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@ -Iinc

$(BUFFIZER) : $(BUFFIZER_OBJ)
	@$(CC) $(FLAGS) $(BUFFIZER_OBJ) -o $@ -Iinc

clean :
	@/bin/rm -f $(BUFFIZER_OBJ)

fclean : clean
	@/bin/rm -f $(BUFFIZER)

re : fclean all
