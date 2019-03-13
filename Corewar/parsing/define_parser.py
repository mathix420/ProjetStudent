# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    define_parser.py                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 17:44:57 by agissing          #+#    #+#              #
#    Updated: 2019/03/13 18:58:08 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

limits = {
    'MAX_PLAYERS': range(1, 5),
    'CYCLE_TO_DIE': [1536],
    'CYCLE_DELTA': [50],
    'NBR_LIVE': range(1, 51),
    'MAX_CHECKS': range(1, 51),
    'REG_NUMBER': range(1, 100),
    'MAX_ARGS_NUMBER': [4],
    'MAX_PLAYERS': [4],
    'T_REG': [1],
    'T_DIR': [2],
    'T_IND': [4],
    'T_LAB': [8],
    'IND_SIZE': [2],
    'REG_SIZE': [4],
#    'DIR_SIZE': [4],
    'REG_CODE': [1],
    'DIR_CODE': [2],
    'IND_CODE': [3]
}

file1 = open("../includes/op.h", "r")
file2 = open("../includes/asm.h", "r")

text = file1.read()
text += file2.read()

def     get_arg(line, key):
    splitted = line.split(key)
    if splitted and len(splitted) > 1:
        for i in range(len(splitted[1])):
            if not splitted[1][i] in ['\t', ' ','\0']:
                return(int(splitted[1][i:]))
    print("error")
    return(-1);
    
def     check(limits):
    for line in text.split('\n'):
        if line and line[0] == '#':
             for key in limits.keys():
                if key in line and get_arg(line, key) in limits[key]:
                    print("OK ::", line, "in [", limits[key][0], ':', limits[key][-1], ']');

check(limits)
