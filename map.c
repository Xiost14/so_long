
#include "so_long.h"

/*
int		check_map(char *tmp_map)
{
	int nbr_cara1;
	int	nbr_cara2;
	int c;

	c = 0;
	nbr_cara1 = 0;
	nbr_cara2 = 0;
	while (tmp_map[c])
	{
		if (tmp_map[c] == '\n')

	}
	while (tmp_map[c])
	{
		if (tmp_map[c] != '0' && tmp_map[c] != '1' && tmp_map[c] != 'C' 
		&& tmp_map[c] 'E' && tmp_map[c] != 'P' && tmp_map[c] != '\n')
			return (0);
		if (tmp_map[c] )
		c++;
	}

}

char	**create_map(char *str)
{
	char	**map;
	int	nbr_y;
	int	c;

	c = 0;
	nbr_x = 0;
	while (str[c])
	{
		if (str[c] == '\n')
			nbr_y++;
		c++;
	}
	map = malloc(sizeof(char *) * nbr_y + 1)
	if (map == NULL)
		return (NULL);
	map[nbr_y] == '\0';
	c = 0;
	while (c < nbr_y)
	{

	}
}

char	*generate_map(char *str)
{
	int c;
	int fd;
	char *tmp;
	char *tmp_map;

	c = 0;
	fd = open(str, O_RDONLY);
	while (tmp = get_next_line(fd) != NULL)
		tmp_map = ft_strjoin(tmp_map, tmp);
	free(tmp);
	close(fd);
	return (tmp_map);
}

int	map(int ac, char **av, t_data *data)
{
	int tmp;
	int len_arg;
	char *tmp_map;

	if (ac != 2)
		return (0);
	if ((len_arg = ft_strlen(av[1])) < 4)
		return (0);
	if (tmp = ft_strnstr(av[1], ".ber", len_arg) == 0)
		return (0);
	if (tmp + 4 != len_arg)
		return (0);
	if (tmp_map = generate_map(av[1]) == NULL)
		return (0);
	if (check_map == 0)
		return (0);
	if (data->map_done = create_map(tmp_map) == NULL)
		return (0);

	return (1);
}*/

int		ft_check_wall(char **map, int len_x, int len_y)
{
	int y;
	int x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		if (y == 0 || y == len_y - 1)
			while (map[y][++x])
				if (map[y][x] != '1')
					return (0);
		else
			if (map[y][0] != '1' || map[y][len_x] != '1')
				return (0);
	}
	return (1);
}

int		ft_check_map_CEP(char **map, int len_x, int len_y)
{
	int C;
	int E;
	int P;
	int y;
	int x;

	y = -1;
	C = 0;
	E = 0;
	P = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x]
		{
			if (map[y][x] == 'C')
				C++;
			if (map[y][x] == 'E')
				E++;
			if (map[y][x] == 'P')
				P++;
		}
	}
	if (C < 1 || E < 1 || P != 1)
		return (0);
	return (1);
}

int		ft_check_map(char **map, int len_x, int len_y)
{
	int y;
	int x;

	y = 0;
	if (len_x == len_y)
		return (0);
	while (map[y] != '\0')
	{
		x = -1;
		while (map[y][++x] != '\0')
			if (map[y][x] != '0' && map[y][x] != '1' 
				&& map[y][x] != 'C'	&& map[y][x] != 'E' 
					&& map[y][x] != 'P')
			return (0);
		y++;
	}
	if (ft_check_wall(map, len_x, len_y) 
		|| ft_check_map_CEP(map, len_x, len_y))
		return (1)
	return (0);
}

char	*generate_map(char *str)
{
	int c;
	int fd;
	char *tmp;
	char *tmp_map;

	c = 0;
	fd = open(str, O_RDONLY);
	while (tmp = get_next_line(fd) != NULL)
		tmp_map = ft_strjoin(tmp_map, tmp);
	free(tmp);
	close(fd);
	return (tmp_map);
// check empti map;
}

int	map(int ac, char **av, t_data *data)
{
	int nbr;
	int nbr_x;
	int c;
	char *str;

	c = -1;
	nbr_x = -1;
	str = generate_map(av[1]);
	while (str[++c])
		if (str[c] == '\n')
			data->len_y++;
	c = -1;
	while (str[++c])
	{
		nbr = 0;
		while (str[c + nbr] != '\n' || str[c + nbr] != '\0')
			nbr++;
		data->len_x[++nbr_x] = nbr;
		c += nbr;
	}
	if (data->len_y < 3)
		return (0);
	c = 0;
	while (++c < data->len_y)
		if (data->len_x[c] != data->len_x[c - 1])
			return (0);
	data->map_done = ft_split(str, '\n');
	if (ft_check_map(data->map_done, data->len_x[0], data->len_y) == 0)
		return (0);
	return (1);
// refaire map
}
