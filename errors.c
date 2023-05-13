/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:54:27 by amdouyah          #+#    #+#             */
/*   Updated: 2023/05/12 12:08:20 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void emptyline(t_s *s)
{
	int	j;

	s->size_y = size_colom(s->map);
	s->size_x = ft_str_len(s->map[0]);
	j = 1;
	// printf("size y :%d\n", s->size_y);
	// printf("size x :%d\n", s->size_x);
	while (s->map[j])
	{
		if (s->size_x != ft_str_len(s->map[j]))
			exit_err();
		j++;
	}
}

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
		{
			j = 0;
			while (s->map[i][j])
			{
				if (s->map[i][0] != '1' || (s->map[i][s->size_x -1] != '1'))
					exit_err();
				else if (s->map[i][j] != '0' && s->map[i][j] != 'E' && s->map[i][j] != 'P'
				&& s->map[i][j] != 'C' && s->map[i][j] != '1')
					exit_err();
				j++;
			}
			
		}
		i++;
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
void	errors(t_s *s)
{
	checkmap(s);
	emptyline(s);
	repeat(s, 'E');
	repeat(s, 'P');
	repeat(s, 'C');
	
}

