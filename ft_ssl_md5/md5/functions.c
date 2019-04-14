/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 18:04:21 by agissing          #+#    #+#             */
/*   Updated: 2019/04/14 20:32:44 by agissing         ###   ########.fr       */
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

uint32_t	leftrot(uint32_t x, uint32_t c)
{
	return ((x << c) | (x >> (32 - c)));
}

void		do_the_work(t_list *lst)
{
	uint32_t	word[4];
	uint32_t	*var;
	uint32_t	*cons;

	word[0] = 0x67452301;
	word[1] = 0xEFCDAB89;
	word[2] = 0x98BADCFE;
	word[3] = 0x10325476;
	var = (uint32_t[64]) {
		7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17,
		22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
		4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
		6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
	};
	cons = (uint32_t[64]) {
		0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
		0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
		0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
		0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
		0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
		0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
		0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
		0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
		0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
		0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
		0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
		0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
		0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
		0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
		0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
		0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391,
	};
	uint32_t	mess[16];
	int			i, f, g;
	uint32_t	wo[4];
	unsigned		j;
	i = 0;
	f = 0;
	g = 0;
	while (lst)
	{
		j = 0;
		while (j < lst->size)
		{
			wo[0] = word[0];//a
			wo[1] = word[1];//b
			wo[2] = word[2];//c
			wo[3] = word[3];//d
			i = -1;
			while (++i < 16)
				mess[i] = 0;
			i = -1;
			while (++i < 16)
			{
				mess[i] = lst->str[i * 4]
					| (lst->str[i * 4 + 1] << 1)
					| (lst->str[i * 4 + 2] << 2)
					| (lst->str[i * 4 + 3] << 3);
				printf("%d - %d\n", i * 4 + 3, lst->size);
			}
			i = -1;
			while (++i < 64)
			{
				if (i >= 0 && i <= 15)
				{
					f = (wo[3] & wo[2]) | ((!wo[1]) & wo[2]);
					g = i;
				}
				else if (i >= 16 && i <= 31)
				{
					f = (wo[3] & wo[1]) | ((!wo[3]) & wo[2]);
					g = (5 * i + 1);
				}
				else if (i >= 32 && i <= 47)
				{
					f = wo[1] ^ wo[2] ^ wo[3];
					g = (3 * i + 5);
				}
				else if (i >= 48 && i <= 63)
				{
					f = wo[2] ^ (wo[1] | (!wo[3]));
					g = (7 * i) % 16;
				}
				f = f + wo[0] + cons[i] + mess[g];
				wo[0] = wo[3];
				wo[3] = wo[2];
				wo[2] = wo[1];
				wo[1] = wo[1] + leftrot(f, var[i]);
				printf("%c - %d\n", mess[g], g);
			}
			word[0] += wo[0];
			word[1] += wo[1];
			word[2] += wo[2];
			word[3] += wo[3];
			j += 64;
		}
		lst = lst->next;
	}
	printf("%x%x%x%x\n", word[0], word[1], word[2], word[3]);
}

