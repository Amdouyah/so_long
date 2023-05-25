/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:46:06 by amdouyah          #+#    #+#             */
/*   Updated: 2023/05/25 15:24:28 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <mlx.h>
typedef struct s_s {
	int		size_y;
	int		size_x;
	char	**map;
	char	**tst;
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	void	*door;
	void	*wall;
	void	*player;
	void	*back;
	void	*coin;
	int 	w;
	int		h;
	int		counter_c;
	
}t_s
;

char	**ft_split(char *s, char c);
void	errors(t_s *s);
void	emptyline(t_s *s);
void	repeat(t_s *s, char c);
void	return_pos(t_s *s);
void	valid_path(char **s);
void	exit_err(void);
int 	size_colom(char **str);
void	check_map(t_s *s);
void	window(t_s *s);
void	c_c(t_s *s);
int		key(int key, t_s *s);
int		exet(t_s *s);
void	up(t_s *s);
void	left(t_s *s);
void	right(t_s *s);
void	down(t_s *s);
void	xpm_image(t_s *s);
#endif