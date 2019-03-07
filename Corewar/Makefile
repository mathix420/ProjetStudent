# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/05 18:04:52 by trlevequ          #+#    #+#              #
#    Updated: 2019/03/07 19:11:51 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# ***                            MF-GEN MAKEFILE                           *** #
# **************************************************************************** #

################################################################################
#####                              FILES VARS                              #####
################################################################################

ASM = asm
COREWAR = corewar
D_OBJ = obj/
D_ASM_OBJ = $(D_OBJ)asm/
D_COREWAR_OBJ = $(D_OBJ)corewar/

#asm
D_ASM = srcs/asm/
_SRC_ASM = asm.c \
			op.c \
			basic.c \
			error.c \
			get_commands.c \
			check_param.c
ASM_SRC = $(addprefix $(D_ASM),$(_SRC_ASM))
ASM_OBJ = $(addprefix $(D_ASM_OBJ),$(_SRC_ASM:.c=.o))

#asm includes
D_ASM_INC = includes/
_ASM_INC = asm.h op.h
ASM_INC = $(addprefix $(D_ASM_INC),$(_ASM_INC))

#corewar
D_COREWAR = srcs/corewar/
_SRC_COREWAR = corewar.c \
			create_arena.c \
			create_champions.c \
			ft_exit.c \
			get_instruction.c \
			check_encodage.c \
			ft_op.c \
			hexa_to_int.c \
			op.c \
			print_map.c \
			parsing_header.c \
			parsing_champion.c \
			parsing_arguments.c \
			print_structure.c
COREWAR_SRC = $(addprefix $(D_COREWAR),$(_SRC_COREWAR))
COREWAR_OBJ = $(addprefix $(D_COREWAR_OBJ),$(_SRC_COREWAR:.c=.o))

#corewar includes
D_COREWAR_INC = includes/
_COREWAR_INC = corewar.h op.h
COREWAR_INC = $(addprefix $(D_COREWAR_INC),$(_COREWAR_INC))

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

all : $(D_ASM_OBJ) $(D_COREWAR_OBJ) $(ASM) $(COREWAR)

#forcing Libft makefile
$(LIBFT) : FORCE
	@make -C libft

#creating objects dir
$(D_ASM_OBJ) :
	@mkdir -p $@
	@printf "\e[94m[OBJ]\e[0m Directory created!\n"

$(D_COREWAR_OBJ) :
	@mkdir -p $@
	@printf "\e[94m[OBJ]\e[0m Directory created!\n"

#creating asm objects
$(D_ASM_OBJ)%.o : $(D_ASM)%.c $(ASM_INC) | $(D_ASM_OBJ)
	@$(CC) $(FLAGS) -c $< -o $@ -Iincludes -Ilibft
	@printf "\e[2K \e[32m[CC]\e[0m %-15s\r" "$<"

#creating asm
$(ASM) : $(ASM_OBJ) $(ASM_INC) $(LIBFT)
	@$(CC) $(FLAGS) $(ASM_OBJ) -o $@ -Iincludes -Ilibft -Llibft -lft
	@printf "\e[2K\e[94m[PRG]\e[0m $@ done!\n\r"

#creating corewar objects
$(D_COREWAR_OBJ)%.o : $(D_COREWAR)%.c $(COREWAR_INC) | $(D_COREWAR_OBJ)
	@$(CC) $(FLAGS) -c $< -o $@ -Iincludes -Ilibft
	@printf "\e[2K \e[32m[CC]\e[0m %-15s\r" "$<"

#creating corewar
$(COREWAR) : $(COREWAR_OBJ) $(COREWAR_INC) $(LIBFT)
	@$(CC) $(FLAGS) $(COREWAR_OBJ) -o $@ -Iincludes -Ilibft -Llibft -lft
	@printf "\e[2K\e[94m[PRG]\e[0m $@ done!\n"

#cleaning
clean :
	@/bin/rm -rf $(D_OBJ)
	@make clean -C libft
	@echo "\033[33m[PRG]\033[0m Cleaning done"

#deep cleaning
fclean :
	@/bin/rm -rf $(D_OBJ)
	@/bin/rm -f $(ASM) $(COREWAR)
	@make fclean -C libft
	@echo "\033[33m[PRG]\033[0m Cleaning done"

#recompile all
re : fclean all

FORCE :
