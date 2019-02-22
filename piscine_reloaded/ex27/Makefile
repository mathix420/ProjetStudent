#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 15:54:26 by agissing          #+#    #+#              #
#    Updated: 2018/11/06 16:30:04 by agissing         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.SILENT :

all :
	gcc -Wall -Werror -Wextra -c src/display_file.c
	gcc -Wall -Werror -Wextra display_file.o -I includes -o ft_display_file

clean :
	rm -f display_file.o

fclean : clean
	rm -f ft_display_file

re : fclean all