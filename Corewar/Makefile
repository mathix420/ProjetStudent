# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 10:43:07 by trlevequ          #+#    #+#              #
#    Updated: 2019/03/01 10:10:59 by jnoe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_PATH	=	includes/

INC			=	includes/corewar.h

SRC_PATH	=	srcs/asm/
SRC_PATH2	=	srcs/corewar/

SRC_NAME 	=	asm.c \
				
SRC_NAME2 	=	corewar.c				\
				create_arena.c			\
				ft_exit.c				\
				create_champions.c		\
				op.c					\
				print_map.c				\
				print_structure.c		\
				print_op_tab.c			\
				hexa_to_int.c			\

OBJ_PATH	=	objs/asm/
OBJ_PATH2	=	objs/corewar/

CPPFLAGS	=	-Iincludes

LDFLAGS		=	-Llibft
LDLIBS		=	-lft

NAME		=	asm
NAME2		=	corewar

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

OBJ_NAME	=	$(SRC_NAME:.c=.o)
OBJ_NAME2	=	$(SRC_NAME2:.c=.o)

SRC			=	$(addprefix $(SRC_PATH),$(SRC_NAME))
SRC2		=	$(addprefix $(SRC_PATH2),$(SRC_NAME2))
OBJ			=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ2		=	$(addprefix $(OBJ_PATH2),$(OBJ_NAME2))

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@
	@echo "$(NAME) created"

$(NAME2): $(OBJ2)
	@make -C libft/
	@$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ2) -o $@
	@echo "$(NAME2) created"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c $(INC)
	@mkdir objs 2> /dev/null || true
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH2)%.o : $(SRC_PATH2)%.c $(INC)
	@mkdir objs 2> /dev/null || true
	@mkdir $(OBJ_PATH2) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

lib_make_fclean:
	@make -C libft/ fclean

lib_make_clean:
	@make -C libft/ clean

clean:
	@rm -rf $(OBJ) $(OBJ2) $(OBJ_PATH) $(OBJ_PATH2)
	@echo "objs suppressed"

fclean: clean lib_make_fclean
	@rm -rf $(NAME) $(NAME2)
	@echo "exec suppressed"

re: lib_make_fclean fclean all

.PHONY:	all, clean, fclean, re
