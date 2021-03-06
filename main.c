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

#include "include/so_long.h"

int	main(int ac, char **av)
{
	t_data data;

	if (ac == 2)
	{
		if (check_arg(av[1]))
			ft_error("Argument is not a correct .ber file.\n", &data);
		create_map(&data, av[1]);
		struc_init(&data);
		check_map(&data);
		get_player(&data);
		init_window(&data);
		init_image(&data);
		render(&data);
	//loop
	//destroy
	//free_fin
	}
	return (0);
}
