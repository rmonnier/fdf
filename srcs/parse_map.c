/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 14:49:28 by rmonnier          #+#    #+#             */
/*   Updated: 2017/01/04 14:55:03 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_z(char *str, int *i)
{
	int		n;
	int		z;

	str += *i;
	n = 0;
	if (str[n] == '+' || str[n] == '-')
		n++;
	if (!ft_isdigit(str[n]))
		fdf_error(MAP_ERROR, NULL);
	z = ft_atoi(str);
	while (ft_isdigit(str[n]))
		n++;
	*i += n;
	return (z);
}

static t_point	*new_point(char *str, int *i, int x, int y)
{
	int			z;
	t_point		*output;

	z = get_z(str, i);
	if (!(output = (t_point*)ft_memalloc(sizeof(t_point))))
		fdf_error(MALL_ERROR, NULL);
	output->x = x;
	output->y = y;
	output->z = z;
	return (output);
}

static int		get_line(t_point **line, char *str, int y)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (str[i])
		{
			*line = new_point(str, &i, x, y);
			line = &((*line)->right);
			x++;
		}
	}
	return (1);
}

static void		get_grid(int fd, t_point **grid)
{
	char	*str;
	int		y;

	y = 0;
	while (get_next_line(fd, &str) == 1)
	{
		get_line(grid, str, y);
		grid = &((*grid)->down);
		y++;
		ft_strdel(&str);
	}
	if (y == 0)
		fdf_error(MAP_ERROR, NULL);
}

t_point			*parse_map(int fd)
{
	t_point	*grid;

	get_grid(fd, &grid);
	connect_dots(grid);
	return (grid);
}
