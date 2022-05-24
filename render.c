/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsamina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:02:54 by thsamina          #+#    #+#             */
/*   Updated: 2022/05/24 14:02:56 by thsamina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	parse_image(t_data *data, int width, int y, int x)
{
	if (data->map_done[y][x] == '1')
		mlx_put_image_to_window(data->mlx, 
			data->win, data->wall, width, y * IMG_SIZE);
	else if (data->map_done[y][x] == '0')
		mlx_put_image_to_window(data->mlx, 
			data->win, data->ground, width, y * IMG_SIZE);
	else if (data->map_done[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, 
			data->win, data->coin, width, y * IMG_SIZE);
	else if (data->map_done[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, 
			data->win, data->player, width, y * IMG_SIZE);
	else if (data->map_done[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, 
			data->win, data->exit, width, y * IMG_SIZE);
}

int	render(t_data *data)
{
	int	y;
	int	x;
	int	width;

	y = 0;
	x = 0;
	width = 0;
	if (data->win)
		return (FAIL);
	while (data->map_done[y])
	{
		while (data->map_done[y][x] && data->map_done[y][x] != '\n')
		{
			parse_image(data, width, y, x);
			width += IMG_SIZE;
			x++;
		}
		x = 0;
		width = 0;
		y++;
	}
	return (SUCCESS);
}