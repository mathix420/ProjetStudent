/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufizer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:35:34 by agissing          #+#    #+#             */
/*   Updated: 2019/03/02 20:26:23 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAIN_FILE
#include "bufizer.h"

void				(*fcts[8])(va_list, char *) = {
	put_str,
	put_char,
	put_digit,
	put_hex,
	put_oct,
	put_bin,
	put_color
};

static int	is_opt(char c)
{
	return ((c == 's') | ((c == 'c') << 1)| ((c == 'd' || c == 'i') << 2)
			| ((c == 'x') << 3) | ((c == 'o') << 4)
			| ((c == 'b') << 5) | ((c == 'g') << 6));
}

static void	parser(va_list lst, char *str)
{
	int		opt;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[++i] && !(opt = is_opt(str[i])))
	{
		write(1, str + i, 1);
		// check args
	}
	if (!str[i])
		exit(1);
	while (!(opt & 1 << j))
		j++;
	fcts[j](lst, str + i);
}

int			bufizer(const char *format, ...)
{
	va_list		valist;
	char		*str;
	int			i;

	i = -1;
	str = (char *)format;
	va_start(valist, format);
	while (str[++i])
		if (str[i] != '%')
			;
		else if (str[i] == '%')
			parser(valist, str + i + 1);
	va_end(valist);
	return (0);
}

int			main()
{
	int		i;

	i = 0;
	while (i++ < 10000000)
	{
		bufizer("%s%s%s", "tesd\n", "testdd\n", "testdd\n");
//		printf("%s%s%s", "tesd\n", "testdd\n", "testdd\n");
	}
	print_all(1);
	return (0);
}
