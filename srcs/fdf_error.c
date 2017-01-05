/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:23:37 by rmonnier          #+#    #+#             */
/*   Updated: 2017/01/05 11:23:40 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_error(int param, char *name)
{
	if (param == USAGE)
		ft_putendl_fd("Usage : ./fdf <filename>", 2);
	else if (param == OPEN_ERROR)
		perror(name);
	else if (param == MAP_ERROR)
		ft_putendl_fd("File error", 2);
	else if (param == MALL_ERROR)
		ft_putendl_fd("Malloc error", 2);
	exit(EXIT_FAILURE);
}
