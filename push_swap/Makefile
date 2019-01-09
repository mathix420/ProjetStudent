#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/09 17:05:40 by agissing          #+#    #+#              #
#    Updated: 2019/01/09 18:40:07 by agissing         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

################################################################################
#####                              FILES VARS                              #####
################################################################################

NAME = push_swap

INC = includes libft

SDIR = srcs
_SRC = checker.c \
		ft_actions.c \
		ft_op.c \
		is_ok.c \
		little_numbers_sort.c \
		output_cleaner.c \
		push_swap.c \
		rr_or_r.c \
		sorting.c \
		sorting_len_three.c \
		swap_if.c

UTILSDIR = utils
_UTILS = ft_free_list.c \
		new_elem.c \
		print_stack.c \
		push.c \
		reverse.c \
		rotate.c \
		swap.c

SRC = $(patsubst %,$(SDIR)/%,$(_SRC)) $(patsubst %,$(UTILSDIR)/%,$(_UTILS))

OBJ = $(SRC:.c=.o)

################################################################################
#####                           COMPILER OPTIONS                           #####
################################################################################

CC = gcc
OPTS = $(foreach d, $(INC), -I$d)
FLAGS = -Wall -Wextra -Werror $(OPTS)

################################################################################
#####                            MAKEFILE RULES                            #####
################################################################################

.PHONY: all clean fclean re

all: $(NAME)

%.o:		%.c
		@$(CC) $(FLAGS) -o $@ -c $<
		@printf "\33[2K  ➡ %-15s%s\r" "$<" "✅"

$(NAME):	$(OBJ)
		@make -C libft
		@$(CC) $(FLAGS) -o $@ -Llibft -lft $(OBJ)
		@printf "\33[2K \r\nPush_swap is done !\n"

clean:
		@printf "\n\e[92m%75s\n" "==================== LIBFT ====================  "
		@make clean -C libft
		@printf "\n\e[94m%75s\n" "==================== PUSH_SWAP ===================="
		@/bin/rm -f $(OBJ)
		@echo "Objects cleaned\033[0m ♻️"

fclean:
		@printf "\n\e[92m%75s\n" "==================== LIBFT ====================  "
		@make fclean -C libft
		@printf "\n\e[94m%75s\n" "==================== PUSH_SWAP ===================="
		@/bin/rm -f $(OBJ)
		@/bin/rm -f $(NAME)
		@echo "Objects cleaned ♻️"
		@echo "Executable deleted\033[0m 🚧 "

re: fclean all
