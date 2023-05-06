/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:46:06 by amdouyah          #+#    #+#             */
/*   Updated: 2023/05/05 15:23:51 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"

typedef struct s_s {
	int		size_y;
	int		size_x;
	char	**map;
}t_s
;

char	**ft_split(char *s, char c);
void	errors(t_s *s);
void	emptyline(t_s *s);

#endif