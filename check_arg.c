/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsamina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:03:13 by thsamina          #+#    #+#             */
/*   Updated: 2022/05/23 14:03:14 by thsamina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	check_extention(char *arg)
{
	int fd;
    int len;

    len = ft_strlen(arg);
    if (open(arg, O_DIRECTORY) >= 0)
    {
        fd = open(arg, O_DIRECTORY);
        close(fd);
        return(FAIL);
    }
    else (len > 4)
    {
        fd = open(arg, O_RDONLY);
        close(fd);
        if (arg[len - 4] == '.' && arg[len - 3] == 'b' && 
            arg[len - 2] == 'e' && arg[len - 1] == 'r')
            return (FAIL);
    }
    return (SUCCESS);
}