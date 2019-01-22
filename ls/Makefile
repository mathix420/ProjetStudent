# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 15:54:25 by kemartin          #+#    #+#              #
#    Updated: 2019/01/22 13:27:21 by kemartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls

SRC		=	main.c \
			option.c \
			list.c \
			ls.c \
			modif.c \
			param.c \
			paths.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g3
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft/includes
FT_LNK	= -L ./libft -l ft

SRCDIR	= ./src/
INCDIR	= ./inc/
OBJDIR	= ./obj/

.PHONY: all, clean, fclean, re

all: obj $(FT_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o : $(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $< -g3
	@echo "Object done."

$(FT_LIB) :
	@make -C $(FT)
	@echo "Libft ok."

$(NAME) : $(OBJ)
	@$(CC) $(OBJ) $(FT_LNK) -o $(NAME)
	@echo "Everything done."

clean :
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean
	@echo "Objects cleaned."

fclean : clean
	@rm -rf $(NAME)
	@make -C $(FT) fclean
	@echo "Everything cleaned."

re: fclean all
