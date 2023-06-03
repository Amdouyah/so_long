/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 01:11:17 by amdouyah          #+#    #+#             */
/*   Updated: 2023/05/26 18:39:05 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish(t_s *s)
{
	looop(s);
	write (1, "GG\n", 3);
	exit(1);
}

void	exit_err(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	exet(t_s *s)
{
	exit(1);
	(void)s;
	return (0);
}

void	emptyline(t_s *s)
{
	int	j;

	s->size_y = size_colom(s->map);
	s->size_x = ft_str_len(s->map[0]);
	j = 1;
	while (s->map[j])
	{
		if (s->size_x != ft_str_len(s->map[j]))
			exit_err();
		j++;
	}
}
