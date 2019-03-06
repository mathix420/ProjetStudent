/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:47:26 by agissing          #+#    #+#             */
/*   Updated: 2019/03/06 12:07:23 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

# include "op.h"
# include "libft.h"

# define COLOR_RED		"\e[91m"
# define COLOR_GREEN	"\e[92m"
# define COLOR_END		"\e[0m"

# define NO_NAME_OR_COMMENT 1
# define BAD_PARAMETER 2
# define BAD_LABEL_NAME 3

#endif
