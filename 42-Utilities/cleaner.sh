# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    cleaner.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 16:42:54 by agissing          #+#    #+#              #
#    Updated: 2019/09/04 09:43:24 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#! /bin/bash

args=$@

# Test if no args put dot

if [ -z $1 ]; then
        args='.'
fi

# Find files to clean

files=$(find $args \
-name '*~' -type f \
-or -name '#*#' -type f \
-or -name 'a.out' -type f \
-or -name '*.dSYM' -type d \
-or -name '.DS_Store' -type f \
-or -name '.zcompdump*' -type f \
-or -name '__pycache__' -type d \
-or -name '*.pyc' -type f \
-or -name '*egg-info' -type d \
2>> /dev/null)


# Test if no result, print an error

if [ -z "$files" ]; then
        echo "clean: Nothing to clean there!" 1>&2
        exit 1
fi

for var in $(echo "$files"); do
        echo $var
done

# Remove all the junk files

rm -rf $files;
