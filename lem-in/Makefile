# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 17:10:19 by agissing          #+#    #+#              #
#    Updated: 2019/02/09 17:10:19 by agissing         ###   ########.fr        #
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
way.c 
LEMIN_SRC = $(patsubst %,$(DIR_SRCS0)/%,$(_SRCS0))

LEMIN_OBJ = $(LEMIN_SRC:.c=.o)
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

$(LEMIN_OBJ) : %.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@ -Iinc -Ilibft

$(LEMIN) : $(LEMIN_OBJ) $(LIBFT)
	@$(CC) $(FLAGS) $(LEMIN_OBJ) -o $@ -Iinc -Ilibft -Llibft -lft

clean :
	@/bin/rm -f $(LEMIN_OBJ)

fclean : clean
	@/bin/rm -f $(LEMIN)

re : fclean all
