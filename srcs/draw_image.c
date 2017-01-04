/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 18:23:48 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/30 18:23:49 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	put_pixel(t_display params, int x, int y)
{
	int				i;
	unsigned int	u;
	int				index;

	i = 0;
	if ((y >= params.height) || (x >= params.width) || x < 0 || y < 0)
		return (0);
	index = y * params.sizeline + x * params.sizecol;
	u = mlx_get_color_value(params.mlx, 0X00FFFFFF);
	while (i < params.sizecol)
	{
		if (!params.endian)
		{
			params.data[index + i] = *(((char*)&u) + i);
		}
		else
		{
			params.data[index + i] = *(((char*)&u) + params.sizecol - i - 1);
		}
		i++;
	}
	return (0);
}

static void	init_linker(t_point *p0, t_point *p1, t_linker *l)
{
	l->dx = ft_abs(p1->xs - p0->xs);
	l->dy = ft_abs(p1->ys - p0->ys);
	l->sx = p0->xs < p1->xs ? 1 : -1;
	l->sy = p0->ys < p1->ys ? 1 : -1;
	l->e1 = (l->dx > l->dy ? l->dx : -(l->dy)) / 2;
	l->x = p0->xs;
	l->y = p0->ys;
}

static int	link_points(t_point *p0, t_point *p1, t_display params)
{
	t_linker l;

	if (!p0 || !p1)
		return (0);
	init_linker(p0, p1, &l);
	while (l.x != p1->xs || l.y != p1->ys)
	{
		put_pixel(params, l.x, l.y);
		l.e2 = l.e1;
		if (l.e2 > -l.dx)
		{
			l.e1 -= l.dy;
			l.x += l.sx;
		}
		if (l.e2 < l.dy)
		{
			l.e1 += l.dx;
			l.y += l.sy;
		}
	}
	return (1);
}

int			draw_image(t_point *grid, t_display params)
{
	t_point	*line;

	params.data = mlx_get_data_addr(params.img, &(params.bpp),
										&(params.sizeline), &(params.endian));
	params.sizecol = params.bpp / 8;
	while (grid)
	{
		line = grid;
		while (line)
		{
			put_pixel(params, line->xs, line->ys);
			link_points(line, line->right, params);
			link_points(line, line->down, params);
			line = line->right;
		}
		grid = grid->down;
	}
	return (1);
}
