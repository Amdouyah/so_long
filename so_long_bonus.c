/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:36:52 by amdouyah          #+#    #+#             */
/*   Updated: 2023/05/29 15:23:51 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_inis(t_s *s)
{
	s->map = NULL;
	s->tst = NULL;
	s->mlx = NULL;
	s->win = NULL;
	s->door = NULL;
	s->wall = NULL;
	s->player = NULL;
	s->back = NULL;
	s->coin = NULL;
	s->join = NULL;
	s->tmp = NULL;
}

void	etc(t_s *s)
{
	s->map = ft_split(s->join, '\n');
	s->tst = ft_split(s->join, '\n');
	errors(s);
	check_map(s);
	window(s);
}

int	main(int ac, char **av)
{
	int		fd;
	t_s		*s;

	if (ac == 2)
	{
		s = malloc(sizeof(t_s));
		ft_inis(s);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			exit_err();
		file_name(av[1]);
		s->tmp = get_next_line(fd);
		if (s->tmp == NULL)
			exit_err();
		while (s->tmp != NULL)
		{
			if (s->tmp[0] == '\n' || s->tmp[0] == '\t' || s->tmp[0] == ' ')
				exit_err();
			s->join = ft_strjoin(s->join, s->tmp);
			free(s->tmp);
			s->tmp = get_next_line(fd);
		}
		etc(s);
		free__(s);
	}
}
