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

static int	my_key_funct(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (1);
}

static int	get_size(t_point *grid, t_display *params)
{
	t_point	*line;

	if (grid)
		compute_screen_view(grid, params, 1);
	while (grid)
	{
		line = grid;
		while (line)
		{
			compute_screen_view(line, params, 0);
			line = line->right;
		}
		grid = grid->down;
	}
	return (1);
}

static int	resize(t_point *grid, t_display *params)
{
	t_point	*line;

	while (((params->xmax - params->xmin) * params->ratio_x) > params->width)
		params->ratio_x -= 1;
	while (((params->ymax - params->ymin) * params->ratio_y) > params->height)
		params->ratio_y -= 1;
	if (!grid)
		return (0);
	while (grid)
	{
		line = grid;
		while (line)
		{
			line->xs = (line->xs - params->xmin) * params->ratio_x;
			line->ys = (line->ys - params->ymin) * params->ratio_y;
			line = line->right;
		}
		grid = grid->down;
	}
	return (1);
}

int			display_map(t_point *grid)
{
	t_display	params;

	params.mlx = mlx_init();
	params.width = WIDTH;
	params.height = HEIGHT;
	params.ratio_x = RATIO_X;
	params.ratio_y = RATIO_Y;
	get_size(grid, &params);
	resize(grid, &params);
	params.win = mlx_new_window(params.mlx, params.width, params.height, "fdf");
	params.img = mlx_new_image(params.mlx, params.width, params.height);
	draw_image(grid, params);
	mlx_put_image_to_window(params.mlx, params.win, params.img, 15, 15);
	mlx_key_hook(params.win, my_key_funct, 0);
	mlx_loop(params.mlx);
	mlx_destroy_image(params.mlx, params.img);
	return (1);
}
