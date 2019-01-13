#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/09 17:05:40 by agissing          #+#    #+#              #
#    Updated: 2019/01/13 17:44:48 by agissing         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

################################################################################
#####                              FILES VARS                              #####
################################################################################

INC = includes libft

PSDIR = srcs/push_swap
_PS =	ft_actions.c \
		ft_op.c \
		is_ok.c \
		little_numbers_sort.c \
		output_cleaner.c \
		push_swap.c \
		rr_or_r.c \
		sorting.c \
		sorting_len_three.c \
		swap_if.c \
		options.c \
		reverse_sort.c \
		is_int.c

CHDIR = srcs/checker
_CH =	checker.c \
		ft_mlx.c \
		ft_op.c \
		ft_print.c \
		ft_treat.c \
		utils.c	\
		options.c \
		ft_error.c \
		checking.c \
		counting.c \
		ft_usage.c \
		ft_isnum.c \
		is_int.c

UTILSDIR = utils
_UTILS = ft_free_list.c \
		new_elem.c \
		print_stack.c \
		push.c \
		reverse.c \
		rotate.c \
		swap.c \
		ft_duplicates.c

PSRC = $(patsubst %,$(PSDIR)/%,$(_PS)) $(patsubst %,$(UTILSDIR)/%,$(_UTILS))
PSOBJ = $(PSRC:.c=.o)

CHSRC = $(patsubst %,$(CHDIR)/%,$(_CH)) $(patsubst %,$(UTILSDIR)/%,$(_UTILS))
CHOBJ = $(CHSRC:.c=.o)

LIBFT = libft/libft.a

MLX = minilibx/libmlx.a

################################################################################
#####                           COMPILER OPTIONS                           #####
################################################################################

CC = gcc
OPTS = $(foreach d, $(INC), -I$d)
FLAGS = -Wall -Wextra -Werror $(OPTS)

################################################################################
#####                            MAKEFILE RULES                            #####
################################################################################

.PHONY: all clean fclean re norm

all: push_swap checker

$(LIBFT):
	@make -C libft

$(MLX):
	@make -C minilibx

%.o:		%.c
	@$(CC) $(FLAGS) -o $@ -c $< -g3
	@printf "\33[2K  ➡ %-40s%s\r" "$<" "✅"

push_swap: $(LIBFT) $(PSOBJ)
	@$(CC) $(FLAGS) -o $@ -Llibft -lft $(PSOBJ)
	@printf "\33[2K \r\nPush_swap is done !\n"

checker: $(LIBFT) $(MLX) $(CHOBJ)
	@$(CC) $(FLAGS) -o $@ -Llibft -lft $(CHOBJ) -L minilibx -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g3
	@printf "\33[2K \r\nChecker is done !\n"

norm:
		norminette includes/ libft/ srcs/checker/ srcs/push_swap/ utils/

clean:
		@make clean -C minilibx
		@printf "\n\e[92m%75s\n" "==================== LIBFT ====================  "
		@make clean -C libft
		@printf "\n\e[94m%75s\n" "==================== PUSH_SWAP ===================="
		@/bin/rm -f $(PSOBJ) $(CHOBJ)
		@echo "Objects cleaned\033[0m ♻️"

fclean:
		@make fclean -C minilibx
		@printf "\n\e[92m%75s\n" "==================== LIBFT ====================  "
		@make fclean -C libft
		@printf "\n\e[94m%75s\n" "==================== PUSH_SWAP ===================="
		@/bin/rm -f $(PSOBJ) $(CHOBJ)
		@/bin/rm -f push_swap checker
		@echo "Objects cleaned ♻️"
		@echo "Executable deleted\033[0m 🚧 "

re: fclean all
