/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_endian.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 12:01:01 by rmonnier          #+#    #+#             */
/*   Updated: 2017/01/05 12:01:15 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		local_endian(void)
{
	int		i;
	char	*c;

	i = 1;
	c = (char*)(&i);
	if (*c == 1)
		return (0);
	else
		return (1);
}
