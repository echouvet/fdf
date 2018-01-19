/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 00:44:03 by echouvet          #+#    #+#             */
/*   Updated: 2018/01/16 00:45:23 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	moreblue(t_a *a)
{
	int		i;
	t_color	color;

	i = 0;
	while (i < a->m.x * a->m.y)
	{
		ft_memcpy(&color, &a->c[i].color, 4);
		color.b++;
		if (color.b > 255)
			color.b = 0;
		ft_memcpy(&a->c[i].color, &color, 4);
		i++;
	}
	a->p = pointset(a);
	empty(a);
	print_window(a);
}

void	lessblue(t_a *a)
{
	int		i;
	t_color	color;

	i = 0;
	while (i < a->m.x * a->m.y)
	{
		ft_memcpy(&color, &a->c[i].color, 4);
		color.b--;
		if (color.b < 0)
			color.b = 255;
		ft_memcpy(&a->c[i].color, &color, 4);
		i++;
	}
	a->p = pointset(a);
	empty(a);
	print_window(a);
}

void	moregreen(t_a *a)
{
	int		i;
	t_color	color;

	i = 0;
	while (i < a->m.x * a->m.y)
	{
		ft_memcpy(&color, &a->c[i].color, 4);
		color.g++;
		if (color.g > 255)
			color.g = 0;
		ft_memcpy(&a->c[i].color, &color, 4);
		i++;
	}
	a->p = pointset(a);
	empty(a);
	print_window(a);
}

void	lessgreen(t_a *a)
{
	int		i;
	t_color	color;

	i = 0;
	while (i < a->m.x * a->m.y)
	{
		ft_memcpy(&color, &a->c[i].color, 4);
		color.g--;
		if (color.g < 0)
			color.g = 255;
		ft_memcpy(&a->c[i].color, &color, 4);
		i++;
	}
	a->p = pointset(a);
	empty(a);
	print_window(a);
}
