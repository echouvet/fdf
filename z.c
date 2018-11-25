/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 00:34:49 by echouvet          #+#    #+#             */
/*   Updated: 2018/01/18 00:34:49 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_z_1(t_a *a)
{
	int i;

	i = 0;
	empty(a);
	a->m.tz += 0.05;
	while (i < a->m.x * a->m.y)
	{
		a->c[i].y = (cos(a->m.tx) * a->r[i].y) - (sin(a->m.tx) * a->r[i].z);
		a->c[i].x = ((cos(a->m.ty) * a->r[i].x) + (sin(a->m.ty) * a->r[i].z));
		a->c[i].x = (cos(a->m.tz) * a->c[i].x) - (sin(a->m.tz) * a->c[i].y);
		a->c[i].y = (sin(a->m.tz) * a->c[i].x) + (cos(a->m.tz) * a->c[i].y);
		i++;
	}
	a->p = pointset(a);
	print_window(a);
}

void	rot_z_0(t_a *a)
{
	int i;

	i = 0;
	empty(a);
	a->m.tz -= 0.05;
	while (i < a->m.x * a->m.y)
	{
		a->c[i].x = ((cos(a->m.ty) * a->r[i].x) + (sin(a->m.ty) * a->r[i].z));
		a->c[i].y = (cos(a->m.tx) * a->r[i].y) - (sin(a->m.tx) * a->r[i].z);
		a->c[i].x = (cos(a->m.tz) * a->c[i].x) - (sin(a->m.tz) * a->c[i].y);
		a->c[i].y = (sin(a->m.tz) * a->c[i].x) + (cos(a->m.tz) * a->c[i].y);
		i++;
	}
	a->p = pointset(a);
	print_window(a);
}
