/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 21:52:05 by echouvet          #+#    #+#             */
/*   Updated: 2018/01/13 21:52:06 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	empty(t_a *a)
{
	int i;

	i = 0;
	while (i < 1500000)
	{
		a->m.pixels[i] = 0;
		i++;
	}
}

t_point	*pointset(t_a *a)
{
	int			j;
	t_point		*p;

	j = 0;
	free(a->p);
	if (!(p = (t_point*)malloc(sizeof(t_point) * a->m.x * a->m.y)))
		error(66);
	while (j < a->m.x * a->m.y)
	{
		p[j].x = (a->m.starting_x + (a->c[j].x * a->m.between_x));
		p[j].y = (a->m.starting_y + (a->c[j].y * a->m.between_y));
		p[j].z = a->c[j].z;
		p[j].color = a->c[j].color;
		j++;
	}
	return (p);
}

void	print_window(t_a *a)
{
	int i;
	int j;

	i = -1;
	while (++i < a->m.x * (a->m.y - 1))
		brasenham(a, a->p[i], a->p[i + a->m.x]);
	i = 0;
	while (i < (a->m.x * a->m.y))
	{
		j = 0;
		while (j < a->m.x)
		{
			if (j + 1 != a->m.x)
				brasenham(a, a->p[i], a->p[i + 1]);
			j++;
			i++;
		}
	}
	print(a, a->p[i].x, a->p[i].y, a->p[i].color);
	mlx_put_image_to_window(a->m.mlx, a->m.win, a->m.img, 0, 0);
}
