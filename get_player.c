/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsamina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:49:39 by thsamina          #+#    #+#             */
/*   Updated: 2022/05/24 11:49:41 by thsamina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	get_player(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (data->map_done[++i])
	{
		while (data->map_done[i][++j])
		{
			if (data->map_done[i][j] == 'P')
			{
				data->player_y = i;
				data->player_x = j;
			}
		}
		j = 0;
	}
}