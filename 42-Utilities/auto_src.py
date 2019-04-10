# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    auto_src.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 15:37:14 by agissing          #+#    #+#              #
#    Updated: 2019/04/10 16:41:03 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys, os, re

if len(sys.argv) != 2:
    exit("Usage :\n\t" + sys.argv[0] + " Makefile_cible")

file = sys.argv[1]
    
if not os.path.isfile(file):
    exit("Bad filename")

fo = open(file, "r")
    
if not fo:
    exit("Error: open fail")

data = fo.read()
fo.close()
    
if not len(data):
    exit("Error: file empty")

regex = r"((?<=#{{AUTO-SRC})((?!#{END}).*\n)*(?=#{END}))"

print(regex, data)

results = re.findall(regex, data)

for elem in results:
    elem, shit = elem
    rule = elem.split('}')[0]
    original_rule = "#{{AUTO-SRC}" + rule + '}'

    infos = dict(item.split("=") for item in rule.split(";"))

    print(infos['name'])
