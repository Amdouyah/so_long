/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:18:28 by amdouyah          #+#    #+#             */
/*   Updated: 2023/05/25 15:31:06 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_s *s)
{
	if (s->map[s->y - 1][s->x] == '0')
	{
		s->map[s->y - 1][s->x] = 'P';
		s->map[s->y][s->x] = '0';
		s->y--;
		xpm_image(s);
	}
	else if (s->map[s->y - 1][s->x] == 'C')
	{
		s->map[s->y - 1][s->x] = 'P';
		s->map[s->y][s->x] = '0';
		s->y--;
		s->counter_c--;
		xpm_image(s);
	}
	else if (s->map[s->y - 1][s->x] == '1')
		{
			s->map[s->y][s->x] = 'P';
			xpm_image(s);
		}
	else if (s->map[s->y - 1][s->x] == 'E' && s->counter_c == 0)
	{
		write (1, "GG\n", 3);
		exit(1);
	}
}

void	down(t_s *s)
{
	if (s->map[s->y + 1][s->x] == '0')
	{
		s->map[s->y + 1][s->x] = 'P';
		s->map[s->y][s->x] = '0';
		s->y++;
		xpm_image(s);
	}
	else if (s->map[s->y + 1][s->x] == 'C')
	{
		s->map[s->y + 1][s->x] = 'P';
		s->map[s->y][s->x] = '0';
		s->y++;
		s->counter_c--;
		xpm_image(s);
	}
	else if (s->map[s->y + 1][s->x] == '1')
		{
			s->map[s->y][s->x] = 'P';
			xpm_image(s);
		}
	else if (s->map[s->y + 1][s->x] == 'E' && s->counter_c == 0)
	{
		write (1, "GG\n", 3);
		exit(1);
	}
}

void	right(t_s *s)
{
	if (s->map[s->y][s->x + 1] == '0')
	{
		s->map[s->y][s->x + 1] = 'P';
		s->map[s->y][s->x] = '0';
		s->x++;
		xpm_image(s);
	}
	else if (s->map[s->y][s->x + 1] == 'C')
	{
		s->map[s->y][s->x + 1] = 'P';
		s->map[s->y][s->x] = '0';
		s->x++;
		s->counter_c--;
		xpm_image(s);
	}
	else if (s->map[s->y][s->x + 1] == '1')
		{
			s->map[s->y][s->x] = 'P';
			xpm_image(s);
		}
	else if (s->map[s->y][s->x + 1] == 'E' && s->counter_c == 0)
	{
		write (1, "GG\n", 3);
		exit(1);
	}
}

void	left(t_s *s)
{
	if (s->map[s->y][s->x - 1] == '0')
	{
		s->map[s->y][s->x - 1] = 'P';
		s->map[s->y][s->x] = '0';
		s->x--;
		xpm_image(s);
	}
	else if (s->map[s->y][s->x - 1] == 'C')
	{
		s->map[s->y][s->x - 1] = 'P';
		s->map[s->y][s->x] = '0';
		s->x--;
		s->counter_c--;
		xpm_image(s);
	}
	else if (s->map[s->y][s->x - 1] == '1')
		{
			s->map[s->y][s->x] = 'P';
			xpm_image(s);
		}
	else if (s->map[s->y][s->x - 1] == 'E' && s->counter_c == 0)
	{
		write (1, "GG\n", 3);
		exit(1);
	}
}

int	key(int keyh, t_s *s)
{
	if (keyh == 53)
		exit(0);
	if (keyh == 13|| keyh == 126)
		up(s);
	if (keyh == 0 || keyh == 123)
		left(s);
	if (keyh == 1 || keyh == 125)
		down(s);
	if (keyh == 2 || keyh == 124)
		right(s);
	return (0);
}