/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:43:13 by amdouyah          #+#    #+#             */
/*   Updated: 2023/05/12 12:09:32 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int 	fd;
		char	*join;
		t_s		*s;
		char	*tmp;
		// int		i;

		s = malloc(sizeof(t_s));
		fd = open(av[1], O_RDONLY);
		tmp = get_next_line(fd);
		while (tmp != NULL)
		{
			if (tmp[0] == '\n' || tmp[0] == '\t' || tmp[0] == ' ')
				exit_err();
			join = ft_strjoin(join, tmp);
			free(tmp);
			tmp = get_next_line(fd);
		}
		s->map = ft_split(join, '\n');
		s->tst = ft_split(join, '\n');
		errors(s);
		check_map(s);
	}	
}