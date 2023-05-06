/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:43:13 by amdouyah          #+#    #+#             */
/*   Updated: 2023/05/05 15:57:31 by amdouyah         ###   ########.fr       */
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
				if (s->map[i][0] != '1' && s->map[i][s->size_x -1] != '1')
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

void	errors(t_s *s)
{
	checkmap(s);
	emptyline(s);
}

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

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int 	fd;
		char	*join;
		t_s		*s;
		char	*tmp;

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
		errors(s);
	}	
}