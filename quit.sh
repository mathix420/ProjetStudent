# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    quit.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/22 22:17:48 by agissing          #+#    #+#              #
#    Updated: 2019/03/26 08:30:44 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

/bin/sh /Users/$USER/42-utilities/sav.sh

clear

echo
echo
echo
echo
echo
echo
echo
echo
echo "Your system will logout in 15sec !"

python3 ~/ratpy.py

sleep 15

osascript -e 'tell app "System Events" to log out'
sleep 1
osascript -e 'tell application "System Events" to keystroke RETURN'
ps -ax | grep "iTerm2" | grep -e "\d /Applications/iTerm.app/Contents/MacOS/iTerm2" | grep -Eo "^[0-9]+" | xargs -I {} kill -9 {}
