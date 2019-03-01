/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:33:14 by jnoe              #+#    #+#             */
/*   Updated: 2018/11/20 18:53:24 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len_tab(char const *s, char c)
{
	int i;
	int l;

	l = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			l++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (l);
}

static int		len_str(char const *s, char c, int i)
{
	int l;

	l = 0;
	while (s[i + l] != '\0' && s[i + l] != c)
		l++;
	return (l);
}

static char		**makestr(char **tab, char const *s, char c, int i)
{
	int j;
	int l;
	int k;

	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		l = len_str(s, c, i);
		if ((tab[j] = ft_strnew(l)) == NULL)
			return (NULL);
		k = -1;
		while (++k < l)
		{
			tab[j][k] = s[i];
			i++;
		}
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char **tab;

	if (s != NULL)
	{
		if ((tab = (char **)malloc(sizeof(*tab) * (len_tab(s, c) + 1))) == NULL)
			return (NULL);
		return (makestr(tab, s, c, 0));
	}
	return (NULL);
}
