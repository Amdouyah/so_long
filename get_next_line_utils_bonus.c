/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:19:10 by amdouyah          #+#    #+#             */
/*   Updated: 2023/05/26 23:16:16 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_str_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_str_len(s1) + ft_str_len(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free (s1);
	return (str);
}

int	ft_str_chr(char *s, int c)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] && s[i] != (char)c)
			i++;
		if (s[i] == (char)c)
			return (1);
	}
	return (0);
}

static int	funcnum(long int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
			i++;
			n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	int			len;
	char		*p;
	long int	n;

	n = nb;
	len = funcnum(n);
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	p[len] = '\0';
	if (n == 0)
		p[0] = '0';
	else if (n < 0)
	{
		p[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		len--;
		p[len] = (n % 10) + '0';
		n /= 10;
	}
	return (p);
}
