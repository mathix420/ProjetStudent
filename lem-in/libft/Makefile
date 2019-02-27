#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:38:41 by agissing          #+#    #+#              #
#    Updated: 2019/02/21 14:49:50 by agissing         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

################################################################################
#####                              FILES VARS                              #####
################################################################################

NAME = libft.a

INC = .

SDIR = .
_SRC =	ft_memset.c 	\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memccpy.c	\
		ft_memmove.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strlen.c		\
		ft_strdup.c		\
		ft_strcpy.c		\
		ft_strncpy.c	\
		ft_strcat.c		\
		ft_strncat.c	\
		ft_strlcat.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strstr.c		\
		ft_strnstr.c	\
		ft_strcmp.c		\
		ft_strncmp.c	\
		ft_atoi.c		\
		ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_memalloc.c	\
		ft_memdel.c		\
		ft_strnew.c		\
		ft_strdel.c		\
		ft_strclr.c		\
		ft_striter.c	\
		ft_striteri.c	\
		ft_strmap.c		\
		ft_strmapi.c	\
		ft_strequ.c		\
		ft_strnequ.c	\
		ft_strsub.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_strsplit.c	\
		ft_itoa.c		\
		ft_putchar.c	\
		ft_putstr.c		\
		ft_putendl.c	\
		ft_putnbr.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_lstnew.c		\
		ft_lstdelone.c	\
		ft_lstdel.c		\
		ft_lstadd.c		\
		ft_lstiter.c	\
		ft_lstmap.c		\
		ft_nblen.c		\
		ft_strrev.c		\
		ft_lstlen.c		\
		ft_abs.c		\
		get_next_line.c
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

OBJ = $(SRC:.c=.o)

################################################################################
#####                           COMPILER OPTIONS                           #####
################################################################################

CC = cc
OPTS = $(foreach d, $(INC), -I$d)
FLAGS = -Wall -Wextra -Werror $(OPTS)

################################################################################
#####                            MAKEFILE RULES                            #####
################################################################################

.PHONY: all clean fclean re

all: $(NAME)

%.o:		%.c
		@$(CC) $(FLAGS) -o $@ -c $<
		@printf "\e[2K \e[32m[CC]\e[0m %-15s\r" "$<"

$(NAME):	$(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@printf "\e[2K\e[94m[LIB]\e[0m Libft done!\n"

clean:
		@/bin/rm -f $(OBJ)
		@echo "\033[31m[DEL]\033[0m Objects ♻️"

fclean:
		@/bin/rm -f $(OBJ)
		@/bin/rm -f $(NAME)
		@echo "\033[31m[DEL]\033[0m Objects ♻️"
		@echo "\033[31m[DEL]\033[0m Library 🚧"

re: fclean all
