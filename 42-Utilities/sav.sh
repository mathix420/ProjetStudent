# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sav.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/22 15:17:48 by agissing          #+#    #+#              #
#    Updated: 2019/02/22 18:49:15 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

home="/Users/$USER"
path="$home/goinfre/ProjetStudent__github"

python3 -c "import subprocess; subprocess.Popen(['/bin/zsh', '-c', 'say Backup starting'])"

rm -rf $path

git clone https://github.com/mathix420/ProjetStudent.git $path

yes | git -C $path rm -rf .

cp -r $home/42/ProjetStudent/* $path/.
cp $home/.zshrc $path/.
cp $home/.emacs $path/.

files=$(cat $home/.sav)

for var in $files; do
	cp -r $home/$var $path/.
done;

gitfiles=$(find $path/* -type d -name ".git")
makefiles=$(find $path -type f -name Makefile)

/bin/rm -rf $gitfiles

for var in $makefiles; do
    make -C $(dirname $var) fclean
done

/bin/sh $home/42-utilities/cleaner.sh $path

git -C $path add .

message="Auto commit $(date)"

git -C $path commit -m "$message"
git -C $path push origin master && cd ~/

#rm -rf $path

printf '\n\e[32mAll done!\n'

python3 -c "import subprocess; subprocess.Popen(['/bin/zsh', '-c', 'say all done bitches'])"
