/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:06:25 by amdouyah          #+#    #+#             */
/*   Updated: 2023/05/26 23:21:20 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_image(t_s *s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < s->size_y)
	{
		j = -1;
		while (++j < s->size_x)
			xpm_image_2(s, i, j);
	}
}

void	xpm_image_2(t_s *s, int i, int j)
{
	if (s->map[i][j] == '1')
		mlx_put_image_to_window(s->mlx, s->win, s->wall,
			j * 50, i * 50);
	if (s->map[i][j] == '0' || s->map[i][j] == 'E'
	|| s->map[i][j] == 'C' || s->map[i][j] == 'P')
		mlx_put_image_to_window(s->mlx, s->win, s->back,
			j * 50, i * 50);
	if (s->map[i][j] == 'P')
		mlx_put_image_to_window(s->mlx, s->win, s->player,
			j * 50, i * 50);
	if (s->map[i][j] == 'C')
		mlx_put_image_to_window(s->mlx, s->win, s->coin,
			j * 50, i * 50);
	if (s->map[i][j] == 'E')
		mlx_put_image_to_window(s->mlx, s->win, s->door,
			j * 50, i * 50);
}

void	window(t_s *s)
{
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, s->size_x * 50, s->size_y * 50, "so_long");
	s->door = mlx_xpm_file_to_image(s->mlx,
			"./textures/door.xpm", &s->w, &s->h);
	s->back = mlx_xpm_file_to_image(s->mlx,
			"./textures/back.xpm", &s->w, &s->h);
	s->coin = mlx_xpm_file_to_image(s->mlx,
			"./textures/coin.xpm", &s->w, &s->h);
	s->player = mlx_xpm_file_to_image(s->mlx,
			"./textures/player.xpm", &s->w, &s->h);
	s->wall = mlx_xpm_file_to_image(s->mlx,
			"./textures/wall.xpm", &s->w, &s->h);
	xpm_image(s);
	s->moves = 0;
	mlx_key_hook(s->win, key, s);
	mlx_hook(s->win, 17, 0, exet, s);
	mlx_loop(s->mlx);
}

void	free__(t_s *s)
{
	free_2d(s->map);
	free_2d(s->tst);
}

void	free_2d(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
