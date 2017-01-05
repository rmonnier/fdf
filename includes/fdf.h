/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:24:41 by rmonnier          #+#    #+#             */
/*   Updated: 2017/01/04 17:45:20 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define HEIGHT 1024
# define WIDTH 2048
# define RATIO_X 20
# define RATIO_Y 20
# define RATIO_Z 2
# define PAD 20

typedef struct	s_linker
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		e1;
	int		e2;

}				t_linker;

typedef struct	s_display
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			sizecol;
	int			endian;
	int			local_endian;
	int			xmin;
	int			xmax;
	int			ymin;
	int			ymax;
	int			width;
	int			height;
	int			ratio_x;
	int			ratio_y;
	int			ratio_z;

}				t_display;

typedef struct	s_point
{
	int				x;
	int				y;
	int				z;
	int				xs;
	int				ys;
	struct s_point	*right;
	struct s_point	*down;
}				t_point;

enum
{
	USAGE,
	OPEN_ERROR,
	MAP_ERROR,
	MALL_ERROR
};

int				fdf_error(int param, char *name);
int	local_endian(void);
t_point			*parse_map(int fd);
int				connect_dots(t_point *grid);
int				display_map(t_point *grid);
int				compute_screen_view(t_point *grid,
									t_display *params, int first);
int				draw_image(t_point *grid, t_display params);

#endif
