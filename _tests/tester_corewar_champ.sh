# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/19 10:18:33 by agissing          #+#    #+#              #
#    Updated: 2019/03/19 15:57:13 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TO_TEST="$HOME/42/ProjetStudent/Corewar/champ.cor"
TO_TEST_SRC="$HOME/42/ProjetStudent/Corewar/champ"

CHAMPS_PATH="$HOME/42/ProjetStudent/Corewar/vm_champs/champs/championships/"
#CHAMPS_PATH="$HOME/42/ProjetStudent/Corewar/vm_champs/champs/championships/2018/bcozic"
VM="$HOME/42/ProjetStudent/Corewar/vm_champs/corewar"

all_champs=$(find $CHAMPS_PATH -type f -name "*.cor")
#all_champs="/Users/agissing/42/ProjetStudent/Corewar/vm_champs/champs/Gagnant.cor"

champ_name=$(tail -c +5 $TO_TEST | head -c 128)

#$HOME/42/ProjetStudent/Corewar/vm_champs/asm $TO_TEST_SRC
#if test $? = 1; then
#	exit
#fi;

count=0
win=0

for champ in $all_champs; do
	echo $(basename $champ) ":"
	time ($VM $champ $TO_TEST > log)
	cat log | tail -n 1 | grep "$champ_name" >> /dev/null
	if test $? = 0; then
		echo "\033[32mWinner !\033[0m"
		let win+=1
	else
		echo "\033[31mLoser !\033[0m"
	fi;
	echo ""
	let count+=1
done;

echo "Result : $win / $count"
cp $TO_TEST_SRC "$HOME/42/ProjetStudent/_sav/corewar_champ/$(date +%T)_sav_$win-$count.s"
