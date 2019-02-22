# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    cleaner.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 16:42:54 by agissing          #+#    #+#              #
#    Updated: 2019/02/22 17:47:58 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

args=$@

# Test if no args put dot

if [ -z $1 ]; then
	args='.'
fi

# Find files to clean

tmp_files=$(find $args -name '*~' -type f 2>> /dev/null)
dump_files=$(find $args -name '#*#' -type f 2>> /dev/null)
gcc_output=$(find $args -name 'a.out' -type f 2>> /dev/null)
valgrind_output=$(find $args -name '*.dSYM' -type d 2>> /dev/null)
ds_store=$(find $args -name '.DS_Store' -type f 2>> /dev/null)
zcompdump=$(find $args -name '.zcompdump*' -type f 2>> /dev/null)

# Test if no result, print an error

if [ -z "$tmp_files$dump_files$gcc_output$valgrind_output$ds_store$zcompdump" ]; then
	echo "clean: Nothing to clean there!" 1>&2
	exit 1
fi

for var in $(echo "$tmp_files $dump_files $gcc_output $valgrind_output $ds_store $zcompdump"); do
	echo $var
done

# Remove all the junk files

(rm -rf $tmp_files $dump_files $gcc_output $valgrind_output $ds_store $zcompdump);
