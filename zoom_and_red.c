/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom+red.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 00:49:08 by echouvet          #+#    #+#             */
/*   Updated: 2018/01/18 00:49:10 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoommore(t_a *a)
{
	a->m.between_y++;
	a->m.between_x++;
	a->p = pointset(a);
	empty(a);
	print_window(a);
}

void	zoomless(t_a *a)
{
	a->m.between_y--;
	a->m.between_x--;
	if (a->m.between_y < 0 || a->m.between_x < 0)
	{
		a->m.between_y = 0;
		a->m.between_x = 0;
	}
	a->p = pointset(a);
	empty(a);
	print_window(a);
}

void	morered(t_a *a)
{
	int		i;
	t_color	color;

	i = 0;
	while (i < a->m.x * a->m.y)
	{
		ft_memcpy(&color, &a->c[i].color, 4);
		color.r++;
		if (color.r > 255)
			color.r = 0;
		ft_memcpy(&a->c[i].color, &color, 4);
		i++;
	}
	a->p = pointset(a);
	empty(a);
	print_window(a);
}

void	lessred(t_a *a)
{
	int		i;
	t_color	color;

	i = 0;
	while (i < a->m.x * a->m.y)
	{
		ft_memcpy(&color, &a->c[i].color, 4);
		color.r--;
		if (color.r < 0)
			color.r = 255;
		ft_memcpy(&a->c[i].color, &color, 4);
		i++;
	}
	a->p = pointset(a);
	empty(a);
	print_window(a);
}
