/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:54:27 by amdouyah          #+#    #+#             */
/*   Updated: 2023/05/26 23:15:41 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	checkmap(t_s *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	s->size_y = size_colom(s->map);
	s->size_x = ft_str_len(s->map[0]);
	while (s->map[i])
	{
		j = 0;
		if (i == 0 || (i == s->size_y - 1))
		{
			while (s->map[i][j])
			{
				if (s->map[i][j] != '1')
					exit_err();
				j++;
			}
		}
		else
			check_map_2(s, i);
		i++;
	}
}

void	check_map_2(t_s *s, int i)
{
	int	j;

	j = 0;
	while (s->map[i][j])
	{
		if (s->map[i][0] != '1' || (s->map[i][s->size_x -1] != '1'))
			exit_err();
		else if (s->map[i][j] != '0' && s->map[i][j] != 'E'
		&& s->map[i][j] != 'P' && s->map[i][j] != 'C'
		&& s->map[i][j] != '1')
			exit_err();
		j++;
	}
}

void	repeat(t_s *s, char c)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = -1;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (s->map[i][j] == c)
				index++;
			j++;
		}
		i++;
	}
	if (c == 'C' && index == -1)
		exit_err();
	else if (c != 'C' && (index > 0 || index == -1))
		exit_err();
}

void	c_c(t_s *s)
{
	int	i;
	int	j;

	i = 0;
	s->counter_c = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (s->map[i][j] == 'C')
				s->counter_c++;
			j++;
		}
		i++;
	}
}

void	errors(t_s *s)
{
	checkmap(s);
	emptyline(s);
	repeat(s, 'E');
	repeat(s, 'P');
	repeat(s, 'C');
	c_c(s);
}
