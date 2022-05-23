/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsamina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:23:47 by thsamina          #+#    #+#             */
/*   Updated: 2022/05/23 14:23:52 by thsamina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int		line_nbr(char path)
{
    int fd;
    int line_count;
    char *line;

    line_count = 0;
    if (fd = open(path, O_RDONLY) < 0)
        ft_putstr("Error: open fail");
    else
    {
        line = get_next_line(fd);
        while (line != NULL)
        {
            line_count++;
            free(line);
            line = get_next_line(fd);
        }
        close(fd);
    }
    return (line_count);
}

void	generate_map(int y, int x, int i, t_data *data)
{
	char *line;

	line = get_next_line(data->fd);
	while (line != NULL)
	{
		data->map_done[y] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->map_done[y])
			return (ft_free(data->map_done));
		while (line[i] != '\0')
			data->map_done[y][x++] = line[i++];
		data->map_done[y++][x] = '\0';
		x = 0;
		i = 0;
		free(line);
		line = get_next_line(data->fd); 
	}
	data->map_done[y] == NULL;
}

void	create_map(t_data *data, char *str_arg)
{
    int y;
    int i;
    int x;

    y = 0;
    i = 0;
    x = 0;
    data->line_count = line_nbr(str_arg);
    data->path_arg = str_arg;
    data->map_done = ft_calloc(data->line_count + 1, sizeof(char *));
    if (!(data->map_done))
        return ;
    if (data->fd = open(str_arg, O_RDONLY) < 0)
        ft_putstr("Error: open fail");
    else
    {
        generate_map(y, x, i, data);
        close(data->fd);
    }
}