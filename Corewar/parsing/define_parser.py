# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    define_parser.py                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 17:44:57 by agissing          #+#    #+#              #
#    Updated: 2019/03/17 17:43:03 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

consulted = []
values = []

limits = {
    'CYCLE_TO_DIE': range(500, 5001),
    'CYCLE_DELTA': range(10, 1001), #CYCLE_DELTA need to be < CYCLE_TO_DIE
    'NBR_LIVE': range(1, 51),
    'MAX_CHECKS': range(1, 51),
    'REG_NUMBER': range(1, 100),
    'MAX_ARGS_NUMBER': range(1, 5), #need to be = to MAX_PLAYERS
    'MAX_PLAYERS': range(1, 5),
    'T_REG': [1],
    'T_DIR': [2],
    'T_IND': [4],
    'T_LAB': [8],
    'MEM_SIZE': [4096],
    'IDX_MOD': range(1, 4096),
    'CHAMP_MAX_SIZE': range(10, 1025),
    'REGISTRE': [1 << 6],
    'DIRECT': [1 << 7],
    'INDIRECT': [3 << 6],
    'IND_SIZE': [2],
    'REG_SIZE': [4],
    'DIR_SIZE': [4],
    'REG_CODE': [1],
    'DIR_CODE': [2],
    'IND_CODE': [3],
    'NO_NAME_OR_COMMENT': [1],
    'BAD_PARAMETER': [2],
    'BAD_LABEL_NAME': [3],
    'BAD_PARAM_NUMBER': [4],
    'UNKNOWN_COMMAND': [5],
    'BAD_QUOTES': [6],
    'BAD_SYNTAXE': [7],
    'LABEL_NAME_EXIST': [8],
    'LIMIT_SIZE': [9],
    'CHAMPION_TO_BIG': [10],
    'CHAMPION_TO_SMALL': [11]
}

def do_op(tab, calcul):
    count = 0
    operation = ''
    for part in tab:
        if '(' in part:
            count += 1
        if ')' in part:
            count += 1
        if count:
            operation += part
    if not calcul:
        return (operation)
    for define in consulted:
        if define in operation:
            operation = operation.replace(define, str(values[consulted.index(define)]))
    return (str(int(eval(operation))))
    
def split_ws_arg(string, calcul):
    string = string.replace('\t', ' ');
    while '  ' in string:
        string = string.replace("  ", ' ');
    tab = string.split(' ')
    if ''.join(tab[:2]) == "#define":
        if '(' in tab[3]:
            return (do_op(tab[3:], calcul))
        return (tab[3])
    elif tab[0] == "#define":
        if '(' in tab[2]:
            return (do_op(tab[2:], calcul))
        return (tab[2])

def split_ws_name(string):
    string = string.replace('\t', ' ');
    while '  ' in string:
        string = string.replace("  ", ' ');
    tab = string.split(' ')
    if ''.join(tab[:2]) == "#define":
        return (tab[2])
    elif tab[0] == "#define":
        return (tab[1])

def put_error(error):
    print('\033[1m' + error + '\033[0m')
    sys.exit(1)

def get_arg(line, limits, key):
    splitted = split_ws_arg(line, True)
    if splitted:
        if splitted in limits.keys():
            if splitted in consulted:
                splitted = values[consulted.index(splitted)]
            else:
                put_error('{} is declared after {}, impossible to assign it\'s value to {}'.format(splitted, key))
        if splitted.isdigit():
            consulted.append(key)
            values.append(splitted)
            return(int(splitted))

    
def check(limits):
    errors = 0
    for line in text.split('\n'):               ## gerer les commentaires multiligne
        if line and line[0] == '#':
            key = split_ws_name(line)
            if key in limits.keys():
                value = get_arg(line, limits, key)
                if value:
                    if value in limits[key]:
                        if len(limits[key]) == 1:
                            prompt = "{:18} \033[92m{:>13} = {}".format(key, split_ws_arg(line, False), limits[key][0]) + "\033[0m"
                        else:
                            prompt = "{:18} \033[92m{:>13} ∈ [{}:{}]".format(key, split_ws_arg(line, False), limits[key][0], limits[key][-1]) + "\033[0m"
                    else:
                        errors = 1
                        if len(limits[key]) == 1:
                            prompt = "{:18} \033[91m{:>13} ≠ {}".format(key, split_ws_arg(line, False), limits[key][0]) + "\033[0m"
                        else:
                            prompt = "{:18} \033[91m{:>13} ∉ [{}:{}]".format(key, split_ws_arg(line, False), limits[key][0], limits[key][-1]) + "\033[0m"
                    print("\033[93m[CHECKING \033[0m{:55}\033[93m]\033[0m".format(prompt))
    return (errors)

print("\033[93m[#######################################################]\033[0m")
print("\033[93m[#####               CHECKING HEADER               #####]\033[0m")
print("\033[93m[#######################################################]\033[0m")
                    
try:
    file1 = open("includes/op.h", "r")
    file2 = open("includes/asm.h", "r")
except:
    put_error('An error occurs when trying to open headers files!')

try:
    text = file1.read()
    file1.close()
    text += file2.read()
    file2.close()
except:
    put_error('An error occurs when trying to read headers files!')
    
ret_val = check(limits)

if len(consulted) != len(limits):
    put_error('One or more macros cannot be checked : {}\nYou may check the norm!'.format(' '.join([i for i in limits.keys() if not i in consulted])))

try:
    verif_file = open(".headers", "w+")
    verif_file.write("OK")
    verif_file.close()
except:
    put_error('An error occurs when trying to create \'.header\' file!')

print("\033[93m[#######################################################]\033[0m")

sys.exit(ret_val);
