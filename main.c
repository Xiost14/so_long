/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsamina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:01:21 by thsamina          #+#    #+#             */
/*   Updated: 2022/05/12 15:01:23 by thsamina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(int ac, char **av)
{
	int len_arg;
	t_data data;

	if (ac != 2)
		return (0);
	if ((len_arg = ft_strlen(av[1])) < 4)
		return (0);
	if ((ft_strnstr(av[1], ".ber", len_arg) == 0)
		&& (ft_strnstr(av[1], ".ber", len_arg) + 4 != len_arg))
		return(0);
	map(ac, av, &data);
}