/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:59:54 by amdouyah          #+#    #+#             */
/*   Updated: 2023/05/26 23:16:21 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	size_colom(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	return_pos(t_s *s)
{
	int	i;
	int	j;

	i = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (s->map[i][j] == 'P')
			{
				s->x = j;
				s->y = i;
			}
			j++;
		}
		i++;
	}
}

void	looop(t_s *s)
{
	s->moves++;
	write (1, "moves : ", 8);
	ft_putnbr(s->moves);
	write (1, "\n", 1);
}

void	file_name(char *str)
{
	int	len;

	len = ft_str_len(str);
	if (!(str[len - 1] == 'r' && str[len - 2] == 'e'
			&& str[len - 3] == 'b' && str[len - 4] == '.'))
		exit_err();
}

void	kteb(t_s *s)
{
	char	*moves;

	moves = ft_itoa(s->moves);
	mlx_string_put (s->mlx, s->win, s->size_x / 2, 0, 16777215, moves);
	free(moves);
}
