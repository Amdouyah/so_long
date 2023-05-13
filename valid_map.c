/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:50:28 by amdouyah          #+#    #+#             */
/*   Updated: 2023/05/12 12:03:13 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_checking(char **s, int x, int y)
{
	if (s[y][x + 1] != '1' && s[y][x + 1] != 'P')
	{
		s[y][x + 1] = 'P';
		path_checking(s, x + 1, y);
	}
	if (s[y][x - 1] != '1' && s[y][x - 1] != 'P')
	{
		s[y][x - 1] = 'P';
		path_checking(s, x - 1, y);
	}
	if (s[y + 1][x] != '1' && s[y + 1][x] != 'P')
	{
		s[y + 1][x] = 'P';
		path_checking(s, x, y + 1);
	}
	if (s[y - 1][x] != '1' && s[y - 1][x] != 'P')
	{
		s[y - 1][x] = 'P';
		path_checking(s, x, y - 1);
	}
}

void	valid_path(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'E' || s[i][j] == 'C')
			{
				write (2, "invalid_path", 12);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_map(t_s *s)
{
	return_pos(s);
	path_checking(s->tst,s->x,s->y);
	valid_path(s->tst);
}
