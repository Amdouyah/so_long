/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:50:28 by amdouyah          #+#    #+#             */
/*   Updated: 2023/05/29 15:28:17 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	path_checking(char **s, int x, int y)
{
	if (s[y][x + 1] != '1' && s[y][x + 1] != 'P' && s[y][x + 1] != 'E' )
	{
		s[y][x + 1] = 'P';
		path_checking(s, x + 1, y);
	}
	if (s[y][x - 1] != '1' && s[y][x - 1] != 'P' && s[y][x - 1] != 'E')
	{
		s[y][x - 1] = 'P';
		path_checking(s, x - 1, y);
	}
	if (s[y + 1][x] != '1' && s[y + 1][x] != 'P' && s[y + 1][x] != 'E')
	{
		s[y + 1][x] = 'P';
		path_checking(s, x, y + 1);
	}
	if (s[y - 1][x] != '1' && s[y - 1][x] != 'P' && s[y - 1][x] != 'E')
	{
		s[y - 1][x] = 'P';
		path_checking(s, x, y - 1);
	}
}

void	exit_pos(t_s *s)
{
	int	i;
	int	j;

	s->exit_x = 0;
	s->exit_y = 0;
	i = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (s->map[i][j] == 'E')
			{
				s->exit_x = j;
				s->exit_y = i;
			}
			j++;
		}
		i++;
	}
}

int	check_exit_path(t_s *s)
{
	int	x;
	int	y;

	x = s->exit_x;
	y = s->exit_y;
	if (s->tst[y][x + 1] == 'P' || s->tst[y][x - 1] == 'P'
		|| s->tst[y + 1][x] == 'P' || s->tst[y - 1][x] == 'P')
		return (1);
	else
		return (0);
}

void	valid_path(char **s, t_s *st)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (check_exit_path(st) == 0)
			{
				write (2, "invalid_path\n", 13);
				exit(1);
			}
			if (s[i][j] == 'C')
			{
				write (2, "invalid_path\n", 13);
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
	exit_pos(s);
	path_checking(s->tst, s->x, s->y);
	valid_path(s->tst, s);
}
