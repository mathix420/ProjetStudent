# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    gen.py                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/12 11:45:24 by agissing          #+#    #+#              #
#    Updated: 2019/02/12 12:14:54 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from random import choice

file = open("map_10k", "w+")

nb_ant = input("Nb fourmis :: ")
nb_node = input("Nb salles :: ")
nb_link = input("Nb liens :: ")

output = str(nb_ant) + '\n'

for i in range(nb_node):
    if (i == 0):
        output += "##start\n"
    elif (i == nb_node - 1):
        output += "##end\n"
    output += str(i) + ' 0 0\n'

for i in range(nb_link):
    output += str(choice(range(nb_node))) + '-' + str(choice(range(nb_node))) + '\n'

file.write(output)

print(output)
