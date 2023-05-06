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
			while (s->map[i][j++])
			{
				if (s->map[i][j] != '1')
					exit_err();
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



int main(int ac, char **av)
{
	if (ac == 2)
	{
		int 	fd;
		char	*join;
		char	*tmp;
		t_s 	*s;

		s = malloc (sizeof(t_s));
		fd = open(av[1], O_RDONLY);
		tmp = get_next_line(fd);
		while (tmp != NULL)
		{
			join = ft_strjoin(join, tmp);
			free(tmp);
			tmp = get_next_line(fd);
		}
		s->map = ft_split(join, '\n');
		errors(s);
	}
}