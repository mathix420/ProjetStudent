# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    spider.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/24 16:32:42 by agissing          #+#    #+#              #
#    Updated: 2019/02/24 17:15:11 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import requests, re

URL = "http://10.12.1.111/.hidden/"

TAB = []

MESS = []

def get_links(url):
    res = requests.get(url)
    for links in res.text.split('\n'):
        search = re.search(r'<a href="([^"]*)"', links)
        if search and not search.groups()[0] in ["../", "README"] and search.groups()[0] not in TAB:
            get_links(url + search.groups()[0])
            TAB.append(search.groups()[0])
        elif search and search.groups()[0] == "README":
            res = requests.get(url + "README")
            if res.text not in MESS:
                MESS.append(res.text)
                print(res.text[:-1])
        
get_links(URL)

print(len(TAB))
