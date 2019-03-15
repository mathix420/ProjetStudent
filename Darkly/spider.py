# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    spider.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/24 16:32:42 by agissing          #+#    #+#              #
#    Updated: 2019/03/15 21:11:14 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import requests, re

URL = "http://10.13.0.177/.hidden/"

MESS = []

def get_links(url, count):
    res = requests.get(url)
    for links in res.text.split('\n'):
        search = re.search(r'<a href="([^"]*)"', links)
        if search and not search.groups()[0] in ["../", "README"]:
            count += 1
            get_links(url + search.groups()[0], count)
        elif search and search.groups()[0] == "README":
            res = requests.get(url + "README")
            if res.text not in MESS:
                MESS.append(res.text)
                print(url, '=>', res.text[:-1])
        
get_links(URL, 0)

print(len(MESS))
