/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:08:41 by amdouyah          #+#    #+#             */
/*   Updated: 2023/05/26 23:15:51 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	word_num(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
			{
				i++;
			}
			n++;
		}
	}
	return (n);
}

static int	word_len(char const *s, char c, int i)
{
	int	a;

	a = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		a++;
	}
	return (a);
}

static char	**alloc(char **p, const char *s, int i, char c)
{
	int	j;
	int	k;

	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			p[j] = malloc(sizeof(char) * (word_len(s, c, i) + 1));
			if (!p[j])
				return (NULL);
			while (s[i] && s[i] != c)
				p[j][k++] = s[i++];
			p[j++][k] = '\0';
		}
	}
	p[j] = NULL;
	return (p);
}

char	**ft_split(char *s, char c)
{
	char	**p;
	int		i;

	p = malloc(sizeof(char *) * (word_num(s, c) + 1));
	if (!p)
		return (NULL);
	i = 0;
	alloc(p, s, i, c);
	return (p);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}
