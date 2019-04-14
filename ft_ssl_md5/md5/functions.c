/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 18:04:21 by agissing          #+#    #+#             */
/*   Updated: 2019/04/14 18:25:52 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ssl_md5.h"

uint32_t	fct_f(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) | ((!x) & z));
}

uint32_t	fct_g(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) | (y & (!z)));
}

uint32_t	fct_h(uint32_t x, uint32_t y, uint32_t z)
{
	return (x ^ y ^ z);
}

uint32_t	fct_i(uint32_t x, uint32_t y, uint32_t z)
{
	return (y ^ (x | (!z)));
}

void		do_the_work(void)
{
	uint64_t	i;
	uint32_t	word[4];
	uint32_t	*var;

	word[0] = 0x67452301;
	word[1] = 0xEFCDAB89;
	word[2] = 0x98BADCFE;
	word[3] = 0x10325476;
	var = (uint32_t[64])
		{
			7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17,
			22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
			4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
			6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
		};
	i = 0;
}
