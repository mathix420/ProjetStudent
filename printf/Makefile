# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 13:12:35 by agissing          #+#    #+#              #
#    Updated: 2018/12/07 13:33:32 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#####                              FILES VARS                              #####
################################################################################

NAME = ft_printf.a

INC = includes \
		libft

SDIR = srcs
_SRC = convert.c \
		ft_printf.c 
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

OBJ = $(SRC:.c=.o)

################################################################################
#####                           COMPILER OPTIONS                           #####
################################################################################

CC = gcc
OPTS = $(foreach d, $(INC), -I$d)
CFLAGS = -Wall -Wextra -Werror $(OPTS)

################################################################################
#####                            MAKEFILE RULES                            #####
################################################################################

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):	$(OBJ)
		@make -C libft
		@ar -rv $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "Compilation done!"

clean:
		@make clean -C libft
		@/bin/rm -f $(OBJ)
		@echo "*.o cleaned!"

fclean: clean
		@make fclean -C libft
		@/bin/rm -f $(NAME)
		@echo "Cleaning done!"

re: clean all
