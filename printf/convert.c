/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:24:38 by agissing          #+#    #+#             */
/*   Updated: 2018/12/06 19:27:37 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putstr(char *str);

void	ft_putnb(long long n)//, int base)
{
	unsigned long long nbr;

	if (n < 0)
		ft_putchar('-');
	nbr = (n < 0) ? -n : n;
	if (nbr >= 10)
	{
		ft_putnb(nbr / 10);
		ft_putnb(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

void		ft_putd(int nb)
{
	ft_putnb(nb);
}

void		ft_puthh(char nb)
{
	ft_putnb((int)nb);
}

void		ft_puth(short nb)
{
	ft_putnb((int)nb);
}

void		ft_putl(long nb)
{
	ft_putnb((long)nb);
}

void		ft_putll(long long nb)
{
	ft_putnb(nb);
}
