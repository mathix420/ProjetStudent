# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ratpy.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/22 19:23:11 by agissing          #+#    #+#              #
#    Updated: 2019/02/22 22:16:28 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import requests, json, os

URL = "https://api-ratp.pierre-grimaud.fr/v3"

HORRAIRES = URL + "/schedules/metros/13/gabriel+peri/A?_format=json"
STATUS = URL + "/traffic/metros/13?_format=json"

r = requests.get(HORRAIRES)
json_file = json.loads(r.text)

print("\033[41;30mProchain Metro:\t%s \033[0m" % json_file['result']['schedules'][0]['message'])
print("\033[42;30mLe suivant:\t%s \033[0m" % json_file['result']['schedules'][1]['message'])

r = requests.get(STATUS)
json_file = json.loads(r.text)

print("\n\033[103;30mInfo traffic ligne 13 :\033[0m\n")
print('\t\033[1;103;30m%s\033[0m' % json_file['result']['message'])
