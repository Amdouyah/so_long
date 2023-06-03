/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:45:33 by amdouyah          #+#    #+#             */
/*   Updated: 2023/05/29 15:25:26 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_s {
	int		size_y;
	int		size_x;
	int		exit_y;
	int		exit_x;
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
	int		w;
	int		h;
	int		counter_c;
	int		moves;
	char	*join;
	char	*tmp;
}t_s
;

int		ft_str_len(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_get_line(char *save);
char	*ft_save(char *save);
int		ft_str_chr(char *s, int c);
char	*ft_read(int fd, char *r);
/*get_next_line*/
char	**ft_split(char *s, char c);
void	errors(t_s *s);
void	emptyline(t_s *s);
void	repeat(t_s *s, char c);
void	valid_path(char **s, t_s *ts);
void	exit_err(void);
int		size_colom(char **str);
void	check_map(t_s *s);
void	check_map_2(t_s *s, int i);
void	window(t_s *s);
void	c_c(t_s *s);
int		key(int key, t_s *s);
int		exet(t_s *s);
void	up(t_s *s);
void	left(t_s *s);
void	right(t_s *s);
void	down(t_s *s);
void	xpm_image(t_s *s);
void	file_name(char *str);
void	ft_putnbr(int nb);
void	looop(t_s *s);
char	*ft_itoa(int nb);
void	kteb(t_s *s);
void	finish(t_s *s);
void	etc(t_s *s);
void	xpm_image_2(t_s *s, int i, int j);
void	free__(t_s *s);
void	free_2d(char **s);
void	ft_inis(t_s *s);
void	return_pos(t_s *s);

#endif