/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsamina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:07:39 by thsamina          #+#    #+#             */
/*   Updated: 2022/05/24 12:07:41 by thsamina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	init_image(t_data *data)
{
	data->ground = mlx_xpm_file_to_image(data->mlx, 
			GROUND, &data->width, &data->height);
	data->exit = mlx_xpm_file_to_image(data->mlx, 
			EXIT, &data->width, &data->height);
	data->wall = mlx_xpm_file_to_image(data->mlx, 
			WALL, &data->width, &data->height);
	data->player = mlx_xpm_file_to_image(data->mlx, 
			PLAYER, &data->width, &data->height);
	data->coin = mlx_xpm_file_to_image(data->mlx, 
			COIN, &data->width, &data->height);
}