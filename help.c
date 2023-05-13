/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:59:54 by amdouyah          #+#    #+#             */
/*   Updated: 2023/05/12 12:02:30 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_err(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int size_colom(char **str)
{
	int i;
	
	i = 0;
	while(str[i])
		i++;
	return(i); 	
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