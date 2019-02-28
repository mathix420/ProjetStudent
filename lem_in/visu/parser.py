# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    parser.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 15:57:48 by agissing          #+#    #+#              #
#    Updated: 2019/02/28 17:43:21 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
import fileinput, json, webbrowser, os

OUTPUT = ""
map = {"nb_ant": 0, "start": "", "end": "", "rooms": {}, "links": [], "steps": []}
nb_line = 0;
links = False;
end_map = False;

start = False;
end = False;

try:
    for line in fileinput.input():
        if (line[0] == '#' and not line in ["##start\n", "##end\n"]):
            pass
        elif (not end_map and line == '\n'):
            if (not end_map):
                end_map = True;
        elif (end_map):
            s_line = line.replace('\n', '').split(' ')
            round = {}
            for move in s_line:
                splt = move.split('-')
                round[splt[0]] = splt[1]
            map["steps"].append(round)
        elif (line == "##start\n"):
            start = True
        elif(line == "##end\n"):
            end = True
        elif (not nb_line):
            map["nb_ant"] = int(line)
        elif (links or '-' in line):
            s_line = line.replace('\n', '').split('-')
            if (not links):
                links = True
            map["links"].append([s_line[0], s_line[1]])
        else:
            s_line = line.replace('\n', '').split(' ')
            if (start):
                map["start"] = s_line[0]
                start = False
            elif (end):
                map["end"] = s_line[0]
                end = False
            coord = {"x": 0, "y": 0}
            coord["x"] = int(s_line[1])
            coord["y"] = int(s_line[2])
            map["rooms"][s_line[0]] = coord
        nb_line += 1

    map_file = open("visu/output.lem", 'w+')
    map_file.write("let MAP = JSON.parse(`%s`)" % json.dumps(map))
    map_file.close()

    webbrowser.open('file:///%s/index.html' % os.path.dirname(os.path.realpath(__file__)))
except Exception as e:
    print("Parse error :\n", e)
