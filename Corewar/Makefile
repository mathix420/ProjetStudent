# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/01 16:30:59 by agissing          #+#    #+#              #
#    Updated: 2019/03/02 16:14:08 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# ***                            MF-GEN MAKEFILE                           *** #
# **************************************************************************** #

################################################################################
#####                              FILES VARS                              #####
################################################################################

ASM = asm
COREWAR = corewar
OBJ_DIR = obj

#asm
D_ASM = srcs/asm
_SRC_ASM = asm.c 
ASM_SRC = $(patsubst %,$(D_ASM)/%,$(_SRC_ASM))
ASM_OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_SRC_ASM:.c=.o))

#asm includes
D_ASM_INC = includes
_ASM_INC = op.h
ASM_INC = $(patsubst %,$(D_ASM_INC)/%,$(_ASM_INC))

#corewar
D_COREWAR = srcs/corewar
_SRC_COREWAR = corewar.c \
			create_arena.c \
			create_champions.c \
			ft_exit.c \
			ft_op.c \
			hexa_to_int.c \
			op.c \
			print_map.c \
			print_structure.c
COREWAR_SRC = $(patsubst %,$(D_COREWAR)/%,$(_SRC_COREWAR))
COREWAR_OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_SRC_COREWAR:.c=.o))

#corewar includes
D_COREWAR_INC = includes
_COREWAR_INC = corewar.h op.h
COREWAR_INC = $(patsubst %,$(D_COREWAR_INC)/%,$(_COREWAR_INC))

#libft
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

all : $(ASM) $(COREWAR)

#forcing Libft makefile
$(LIBFT) : FORCE
	@make -C libft

#creating objects dir
$(OBJ_DIR) :
	@mkdir -p $@
	@printf "\e[94m[OBJ]\e[0m Directory created!\n"

#creating asm objects
$(ASM_OBJ) : $(OBJ_DIR)%.o : $(D_ASM)%.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@ -Iincludes -Ilibft
	@printf "\e[2K \e[32m[CC]\e[0m %-15s\r" "$<"

#creating asm
$(ASM) : $(ASM_OBJ) $(ASM_INC) $(LIBFT)
	@$(CC) $(FLAGS) $(ASM_OBJ) -o $@ -Iincludes -Ilibft -Llibft -lft
	@printf "\e[2K\e[94m[PRG]\e[0m $@ done!\n\r"

#creating corewar objects
$(COREWAR_OBJ) : $(OBJ_DIR)%.o : $(D_COREWAR)%.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@ -Iincludes -Ilibft
	@printf "\e[2K \e[32m[CC]\e[0m %-15s\r" "$<"

#creating corewar
$(COREWAR) : $(COREWAR_OBJ) $(COREWAR_INC) $(LIBFT)
	@$(CC) $(FLAGS) $(COREWAR_OBJ) -o $@ -Iincludes -Ilibft -Llibft -lft
	@printf "\e[2K\e[94m[PRG]\e[0m $@ done!\n"

#cleaning
clean :
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C libft
	@echo "\033[33m[PRG]\033[0m Cleaning done"

#deep cleaning
fclean :
	@/bin/rm -rf $(OBJ_DIR)	
	@/bin/rm -f $(ASM) $(COREWAR)
	@make fclean -C libft
	@echo "\033[33m[PRG]\033[0m Cleaning done"

#recompile all
re : fclean all

FORCE :
