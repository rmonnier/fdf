/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_screen_view.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:24:53 by rmonnier          #+#    #+#             */
/*   Updated: 2017/01/05 11:24:55 by rmonnier         ###   ########.fr       */
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
