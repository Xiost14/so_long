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

#include "get_next_line.h"


int	main(int ac, char **av)
{
	char	*str;
	int fd;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	while ((str = get_next_line(fd)) != NULL)
		printf("ligne = %s\n", str);
	close(fd);
	free(str);
	return (0);
}