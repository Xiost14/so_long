/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsamina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:23:07 by thsamina          #+#    #+#             */
/*   Updated: 2022/05/16 11:23:09 by thsamina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_check_wall(char **map, int len_x, int len_y)
{
	int y;
	int x;

	y = 0;
	x = -1;
	while (map[y][++x])
		if (map[y][x] != '1')
				return (0);
	while (y < len_y - 1)
	{
		if (map[y][0] != '1' || map[y][len_x] != '1')
		y++;
	}
	x = -1;
	while (map[len_y - 1][++x])
		if (map[len_y - 1][x] != '1')
				return (0);
	return (1);
}

int		ft_check_map_CEP(char **map)
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
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x])
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
	if (!ft_check_wall(map, len_x, len_y) && !ft_check_map_CEP(map))
		return (1);
	if (!ft_check_map_CEP(map))
		return (1);
	while (map[y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
			if (map[y][x] != '0' && map[y][x] != '1' 
				&& map[y][x] != 'C'	&& map[y][x] != 'E' 
					&& map[y][x] != 'P')
			return (0);
		y++;
	}
	return (0);
}
