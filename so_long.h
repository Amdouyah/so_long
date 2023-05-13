/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:46:06 by amdouyah          #+#    #+#             */
/*   Updated: 2023/05/12 12:03:21 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"

typedef struct s_s {
	int		size_y;
	int		size_x;
	char	**map;
	char	**tst;
	int		x;
	int		y;
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

#endif