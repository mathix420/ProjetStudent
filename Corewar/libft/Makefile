# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnoe <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 13:10:17 by jnoe              #+#    #+#              #
#    Updated: 2019/01/25 14:46:03 by jnoe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Werror -Wall -Wextra

SRC = ft_strnstr.c ft_strcmp.c ft_tolower.c ft_bzero.c \
	ft_toupper.c ft_strdup.c ft_memchr.c ft_strstr.c \
	ft_isdigit.c ft_strncat.c ft_memccpy.c ft_isprint.c \
	ft_memcmp.c ft_memcpy.c ft_strcpy.c ft_strncpy.c \
	ft_strchr.c ft_isascii.c ft_isalpha.c ft_strlcat.c \
	ft_memset.c ft_strrchr.c ft_strcat.c ft_atoi.c \
	ft_memmove.c ft_isalnum.c ft_strncmp.c ft_strlen.c \
	ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
	ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
	ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
	ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
	ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	ft_strndup.c ft_strnlen.c ft_lstfree.c ft_lstprint.c \
	ft_isblank.c ft_isspace.c get_next_line.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "lib created"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean: 
	@/bin/rm -f $(OBJ)
	@echo "libft obj suppressed"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "lib suppressed"

re: fclean all
