/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsamina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:51:42 by thsamina          #+#    #+#             */
/*   Updated: 2022/05/23 15:51:44 by thsamina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	check_CPE(t_data *data)
{
	while (data->map_done[data->i])
	{
		while (data->map_done[data->i][data->j])
		{
			if (data->map_done[data->i][data->j] == 'P')
				data->count_p++;
			else if (data->map_done[data->i][data->j] == 'E')
				data->count_e++;
			else if (data->map_done[data->i][data->j] == 'C')
				data->count_c++;
			data->j++;
		}
		data->j = 0;
		data->i++;
	}
	if (!data->count_c || !data->count_e || !data->count_p)
		return (FAIL);
	else
		return (SUCCESS);
}

int	check_bing_end(int y, char **map)
{
	int	i;

	i = 0;
	while (map[y][i] && map[y][i] != '\n')
	{
		if (map[y][i] != '1')
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	check_wall(int line_count, char **map)
{
	int	i;

	i = -1;
	if (check_bing_end(0, map) == FAIL 
		|| check_bing_end(line_count, map) == FAIL)
		return (FAIL);
	while (i < line_count)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 2] != '1')
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	check_rectangle(t_data *data)
{
	int	i;
	size_t j;

	i = 0;
	j = 0;
	data->line_len = ft_strlen(data->map_done[i]) - 1;
	while (data->map_done[i])
	{
		while (data->map_done[i][j] && data->map_done[i][j] != '\n')
			j++;
		if (j != data->line_len)
			return (FAIL);
		j = 0;
		i++;
	}
	return (SUCCESS);
}

int	check_map(t_data *data)
{
	int 	i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->map_done[i])
	{
		while(j < ft_strlen(data->map_done[i][j]) == NULL)
		{
			if (ft_strchr("01CEP", data->map_done[i][j]) == NULL)
				ft_error("A character is not valid.\n", data);
			j++;
		}
		j = 0;
		i++;
	}
	if (check_CPE(data) == FAIL)
		ft_error("One of the character is missing\n", data);
	if (data->count_p)
		ft_error("Too many player\n", data);
	if (check_rectangle(data) == FAIL)
		ft_error("The map is not a rectangle.\n", data);
	if (check_wall(data->line_count - 1, data->map_done) == FAIL)
		ft_error("The edges of the map are invalid\n", data);
	return (SUCCESS);
}