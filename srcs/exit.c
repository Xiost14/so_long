/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsamina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:12:10 by thsamina          #+#    #+#             */
/*   Updated: 2022/05/16 15:12:15 by thsamina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void    ft_putstr(char *str)
{
    int c;

    c = -1;
    while (str[++c])
        write(1, &str[c], 1);
}

void    ft_exit(t_data *data, char *str)
{
    free(data->map_done);
    free(data->str);
    ft_putstr(str);
    exit(1);
}