/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsamina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:39:30 by thsamina          #+#    #+#             */
/*   Updated: 2022/05/23 15:39:31 by thsamina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	struc_init(t_data *data)
{
	data->i = 0;
	data->j = 0;
	data->count_p = 0;
	data->count_e = 0;
	data->count_c = 0;
	data->collect = 0;
	data->can_exit = 0;
	data->steps_count = 0;
	data->win_height = data->line_count * IMG_SIZE;
	data->height = IMG_SIZE;
	data->win_width = (ft_strlen(data->map_done[0]) - 1) * IMG_SIZE;
	data->width = IMG_SIZE;
}