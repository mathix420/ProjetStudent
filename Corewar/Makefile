# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/05 18:04:52 by trlevequ          #+#    #+#              #
#    Updated: 2019/04/14 13:19:06 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# ***                            MF-GEN MAKEFILE                           *** #
# **************************************************************************** #

################################################################################
#####                              FILES VARS                              #####
################################################################################

ASM = asm
COREWAR = corewar

#includes
D_INCLUDES = includes/

#objetcs
D_OBJ = obj/
D_ASM_OBJ = $(D_OBJ)asm/
D_COREWAR_OBJ = $(D_OBJ)corewar/

#asm
D_ASM = srcs/asm/
_SRC_ASM = asm.c \
			op.c \
			basic.c \
			label.c \
			free.c \
			error.c \
			output.c \
			trace.c \
			operators.c \
			num_parser.c \
			overflow.c \
			get_op.c \
			get_commands.c \
			get_label_name.c \
			check_param.c \
			get_param.c
ASM_SRC = $(addprefix $(D_ASM),$(_SRC_ASM))
ASM_OBJ = $(addprefix $(D_ASM_OBJ),$(_SRC_ASM:.c=.o))

#asm includes
_ASM_INC = asm.h op.h
ASM_INC = $(addprefix $(D_INCLUDES),$(_ASM_INC))

#corewar
D_COREWAR = srcs/corewar/
_SRC_COREWAR = corewar.c \
			create_arena.c \
			create_champions.c \
			ft_exit.c \
			get_instruction.c \
			check_encodage.c \
			hexa_to_int.c \
			op.c \
			kill_process.c \
			corewar_check.c \
			winner.c \
			delete_arena.c \
			delete_list_arena.c \
			add_cycle_to_list.c \
			copy_processes.c \
			init_graphic.c \
			graphic_infos.c \
			graphic_breakdown.c \
			graphic_commands.c \
			graphic_winner.c \
			graphic.c \
			print_map.c \
			parsing_header.c \
			parsing_champion.c \
			parsing_utilities.c \
			parsing_arguments.c \
			utilities.c \
			live.c \
			ld.c \
			st.c \
			operations.c \
			zjmp.c \
			fork.c \
			useless.c 

COREWAR_SRC = $(addprefix $(D_COREWAR),$(_SRC_COREWAR))
COREWAR_OBJ = $(addprefix $(D_COREWAR_OBJ),$(_SRC_COREWAR:.c=.o))

#corewar includes
_COREWAR_INC = corewar.h op.h
COREWAR_INC = $(addprefix $(D_INCLUDES),$(_COREWAR_INC))

#libft
LIBFT = libft/libft.a

#Header check
DEFINE_CHECKER_SRC = parsing/define_parser.py
DOT_HEADER = .headers

################################################################################
#####                           COMPILER OPTIONS                           #####
################################################################################

CC = gcc
FLAGS = -Wall -Wextra -Werror
NCURSES_LIB = -lncurses

################################################################################
#####                            MAKEFILE RULES                            #####
################################################################################

.PHONY : all clean fclean re

all : $(D_ASM_OBJ) $(D_COREWAR_OBJ) $(ASM) $(COREWAR)

#checking all defines
$(DOT_HEADER) : $(ASM_INC) $(COREWAR_INC)
	@if ! python3 $(DEFINE_CHECKER_SRC); then exit 1; fi;

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
$(D_ASM_OBJ)%.o : $(D_ASM)%.c $(ASM_INC) $(DOT_HEADER) Makefile | $(D_ASM_OBJ)
	@$(CC) $(FLAGS) -c $< -o $@ -Iincludes -Ilibft
	@printf "\e[2K \e[32m[CC]\e[0m %-15s\r" "$<"

#creating asm
$(ASM) : $(LIBFT) $(ASM_OBJ) $(ASM_INC) Makefile
	@$(CC) $(FLAGS) $(ASM_OBJ) -o $@ -Iincludes -Ilibft -Llibft -lft
	@printf "\e[2K\e[94m[PRG]\e[0m $@ done!\n\r"

#creating corewar objects
$(D_COREWAR_OBJ)%.o : $(D_COREWAR)%.c $(COREWAR_INC) $(DOT_HEADER) Makefile | $(D_COREWAR_OBJ)
	@$(CC) $(FLAGS) -c $< -o $@ -Iincludes -Ilibft
	@printf "\e[2K \e[32m[CC]\e[0m %-15s\r" "$<"

#creating corewar
$(COREWAR) : $(LIBFT) $(COREWAR_OBJ) $(COREWAR_INC) Makefile
	@$(CC) $(NCURSES_LIB) $(FLAGS) $(COREWAR_OBJ) -o $@ -Iincludes -Ilibft -Llibft -lft
	@printf "\e[2K\e[94m[PRG]\e[0m $@ done!\n"

#cleaning
clean :
	@/bin/rm -rf $(D_OBJ) $(DOT_HEADER)
	@make clean -C libft
	@echo "\033[33m[PRG]\033[0m Cleaning done"

#deep cleaning
fclean :
	@/bin/rm -rf $(D_OBJ)
	@/bin/rm -f $(ASM) $(COREWAR) $(DOT_HEADER)
	@make fclean -C libft
	@echo "\033[33m[PRG]\033[0m Cleaning done"

#recompile all
re : fclean all

FORCE :
