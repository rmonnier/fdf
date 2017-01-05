/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 18:23:48 by rmonnier          #+#    #+#             */
/*   Updated: 2017/01/05 11:39:55 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	int		fd;
	t_point	*grid;

	if (ac != 2)
		return (fdf_error(USAGE, NULL));
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (fdf_error(OPEN_ERROR, av[1]));
	grid = parse_map(fd);
	display_map(grid);
	close(fd);
	return (1);
}
