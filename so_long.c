/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:43:13 by amdouyah          #+#    #+#             */
/*   Updated: 2023/05/25 22:09:49 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	xpm_image(t_s *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->size_y)
	{
		j = 0;
		while (j < s->size_x)
		{
			if (s->map[i][j] == '1')
				mlx_put_image_to_window(s->mlx, s->win, s->wall, j * 50, i * 50);
			if (s->map[i][j] == '0' || s->map[i][j] == 'E' || s->map[i][j] == 'C' || s->map[i][j] == 'P')
				mlx_put_image_to_window(s->mlx, s->win, s->back, j * 50, i * 50);
			if (s->map[i][j] == 'P')
				mlx_put_image_to_window(s->mlx, s->win, s->player, j * 50, i * 50);
			if (s->map[i][j] == 'C')
				mlx_put_image_to_window(s->mlx, s->win, s->coin, j * 50, i * 50);
			if (s->map[i][j] == 'E')
				mlx_put_image_to_window(s->mlx, s->win, s->door, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	window(t_s *s)
{
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, s->size_x * 50, s->size_y * 50, "so_long");
	s->door = mlx_xpm_file_to_image(s->mlx, "./textures/door.xpm", &s->w, &s->h);
	s->back = mlx_xpm_file_to_image(s->mlx, "./textures/back.xpm", &s->w, &s->h);
	s->coin = mlx_xpm_file_to_image(s->mlx, "./textures/coin.xpm", &s->w, &s->h);
	s->player = mlx_xpm_file_to_image(s->mlx, "./textures/player.xpm", &s->w, &s->h);
	s->wall = mlx_xpm_file_to_image(s->mlx,"./textures/wall.xpm", &s->w, &s->h);
	xpm_image(s);
	mlx_key_hook(s->win, key, s);
	mlx_hook(s->win, 17, 0, exet, s);
	mlx_loop(s->mlx);
	
}

int	exet(t_s *s)
{
	exit(1);
	(void)s;
	return (0);
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
		if(fd == -1)
			exit_err();
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
		window(s);
	}	
}