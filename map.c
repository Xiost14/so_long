#include "so_long.h"

char	*generate_map(char *str)
{
	int fd;
	int i;
	char *buff;
	char *map;

	fd = open(str, O_RDONLY);
	buff = malloc((50 + 1) * sizeof(char));		
	map = (char *)malloc(1 * sizeof(char));
	map[0] = '\0';
	if (!buff || !map)
		return (NULL);
	i = 1;
	while(i != 0)
	{
		i = read(fd, buff, 50);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		map = ft_strjoin(map, buff);
	}
	free(buff);
	if(map != NULL)
		return (map);
	return (NULL);
}

int check_nbr_len_x(int len_y, int *len_x)
{
	int c;

	c = 0;
	while (++c < len_y)
	{
		if (len_x[c] != len_x[c - 1])
			return (0);
	}
	if (len_x[0] == len_y)
		return (0);
	return (1);
}

int	get_len_x(char *str, int len_y)
{
	int	c;
	int	nbr_x;
	int	nbr;
	int	*len_x;

	c = -1;
	nbr_x = -1;
	len_x = malloc(sizeof(int) * len_y);
	if (!len_x)
		return (0);
	while (str[++c])
	{
		nbr = 0;
		while (str[c + nbr] != '\n' && str[c + nbr] != '\0')
			nbr++;
		len_x[++nbr_x] = nbr;
		c += nbr;
	}
	if (!check_nbr_len_x(len_y, len_x))
	{
		free(len_x);
		return (0);
	}
	nbr = len_x[0];
	free(len_x);
	return (nbr);
}

int	get_len_y(char *str)
{
	int c;
	int len_y;

	c = -1;
	len_y = 0;
	while (str[++c])
		if (str[c] == '\n')
			len_y++;
	if (len_y < 3)
		return (0);
	return (len_y);
}

int	map(int ac, char **av, t_data *data)
{
	char *check_ber;
	int	len_arg;
	char *str;

	if (ac != 2)
		return (0);
	if ((len_arg = ft_strlen(av[1])) < 4)
		return (0);
	if ((check_ber = ft_strnstr(av[1], ".ber", len_arg)) == NULL)
		return (0);
	if ((check_ber = ft_strnstr(check_ber, ".ber", 4)) == NULL)
		return (0);
	str = generate_map(av[1]);
	if (str == NULL)
	{
		free(str);
		return (0);
	}
	data->len_y = get_len_y(str);
	data->len_x = get_len_x(str, data->len_y);
	if (data->len_x == 0)
		return(0);
	data->map_done = ft_split(str, '\n');
	free(str);
	if (ft_check_map(data->map_done, data->len_x, data->len_y) == 0)
		return (1);
	return (0);
}
