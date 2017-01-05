/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_dots.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:25:01 by rmonnier          #+#    #+#             */
/*   Updated: 2017/01/05 11:25:02 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		connect_dots(t_point *grid)
{
	t_point *line1;
	t_point *line2;

	while (grid)
	{
		line1 = grid;
		line2 = grid->down;
		while (line1 && line2)
		{
			line1->down = line2;
			line1 = line1->right;
			line2 = line2->right;
		}
		grid = grid->down;
	}
	return (1);
}
