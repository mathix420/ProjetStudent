/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:47:02 by agissing          #+#    #+#             */
/*   Updated: 2018/11/05 16:59:32 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar('\n');
}

void	ft_putargs(int c, char **args)
{
	int		i;

	i = 1;
	while (i < c)
		ft_putstr(args[i++]);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int		main(int c, char **v)
{
	int		i;
	char	*tmp;

	i = 2;
	while (i < c)
	{
		if (ft_strcmp(v[i - 1], v[i]) > 0)
		{
			tmp = v[i - 1];
			v[i - 1] = v[i];
			v[i] = tmp;
			i = 1;
		}
		i++;
	}
	ft_putargs(c, v);
}
