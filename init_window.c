/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsamina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:57:49 by thsamina          #+#    #+#             */
/*   Updated: 2022/05/24 11:57:51 by thsamina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (ERROR);
	data->win = mlx_new_window(data->mlx, data->win_width, 
			data->win_height, "so_long");
	if (data->win = NULL)
	{
		free(data->win);
		return (ERROR);
	}
	return (SUCCESS);
}