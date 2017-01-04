/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 18:23:48 by rmonnier          #+#    #+#             */
/*   Updated: 2017/01/04 14:47:10 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	compute_screen_view(t_point *grid, t_display *params, int first)
{
	grid->xs = grid->x - grid->y;
	grid->ys = grid->y + grid->x - (grid->z / RATIO_Z);
	if (first)
	{
		params->xmax = grid->xs;
		params->xmin = grid->xs;
		params->ymax = grid->ys;
		params->ymin = grid->ys;
	}
	else
	{
		if (grid->xs > params->xmax)
			params->xmax = grid->xs;
		else if (grid->xs < params->xmin)
			params->xmin = grid->xs;
		if (grid->ys > params->ymax)
			params->ymax = grid->ys;
		else if (grid->ys < params->ymin)
			params->ymin = grid->ys;
	}
	return (1);
}
