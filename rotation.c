/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 01:18:18 by echouvet          #+#    #+#             */
/*   Updated: 2018/01/14 01:18:19 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_x_up(t_a *a)
{
	int i;

	i = 0;
	empty(a);
	a->m.tx += 0.05;
	while (i < a->m.x * a->m.y)
	{
		a->c[i].z = ((cos(a->m.ty) * a->r[i].z) - (sin(a->m.ty)) * a->r[i].x);
		a->c[i].y = (sin(a->m.tz) * a->r[i].x) + (cos(a->m.tz) * a->r[i].y);
		a->c[i].y = (cos(a->m.tx) * a->c[i].y) - (sin(a->m.tx) * a->c[i].z);
		a->c[i].z = (sin(a->m.tx) * a->c[i].y) + (cos(a->m.tx) * a->c[i].z);
		i++;
	}
	a->p = pointset(a);
	print_window(a);
}

void	rot_x_down(t_a *a)
{
	int i;

	i = 0;
	empty(a);
	a->m.tx -= 0.05;
	while (i < a->m.x * a->m.y)
	{
		a->c[i].z = ((cos(a->m.ty) * a->r[i].z) - (sin(a->m.ty)) * a->r[i].x);
		a->c[i].y = (sin(a->m.tz) * a->r[i].x) + (cos(a->m.tz) * a->r[i].y);
		a->c[i].y = (cos(a->m.tx) * a->c[i].y) - (sin(a->m.tx) * a->c[i].z);
		a->c[i].z = (sin(a->m.tx) * a->c[i].y) + (cos(a->m.tx) * a->c[i].z);
		i++;
	}
	a->p = pointset(a);
	print_window(a);
}

void	rot_y_right(t_a *a)
{
	int i;

	i = 0;
	empty(a);
	a->m.ty += 0.05;
	while (i < a->m.x * a->m.y)
	{
		a->c[i].z = (sin(a->m.tx) * a->r[i].y) + (cos(a->m.tx) * a->r[i].z);
		a->c[i].x = (cos(a->m.tz) * a->r[i].x) - (sin(a->m.tz) * a->r[i].y);
		a->c[i].x = ((cos(a->m.ty) * a->c[i].x) + (sin(a->m.ty) * a->c[i].z));
		a->c[i].z = ((cos(a->m.ty) * a->c[i].z) - (sin(a->m.ty)) * a->c[i].x);
		i++;
	}
	a->p = pointset(a);
	print_window(a);
}

void	rot_y_left(t_a *a)
{
	int i;

	i = 0;
	empty(a);
	a->m.ty -= 0.05;
	while (i < a->m.x * a->m.y)
	{
		a->c[i].z = (sin(a->m.tx) * a->r[i].y) + (cos(a->m.tx) * a->r[i].z);
		a->c[i].x = (cos(a->m.tz) * a->r[i].x) - (sin(a->m.tz) * a->r[i].y);
		a->c[i].x = ((cos(a->m.ty) * a->c[i].x) + (sin(a->m.ty) * a->c[i].z));
		a->c[i].z = ((cos(a->m.ty) * a->c[i].z) - (sin(a->m.ty)) * a->c[i].x);
		i++;
	}
	a->p = pointset(a);
	print_window(a);
}
