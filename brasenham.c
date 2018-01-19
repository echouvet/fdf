/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brasenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 01:07:54 by echouvet          #+#    #+#             */
/*   Updated: 2018/01/16 01:13:05 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print(t_a *a, int x, int y, int color)
{
	if (x >= 0 && x < 1500 && y >= 0 && y < 1000)
		a->m.pixels[y * 1500 + x] = color;
}

void	horizontalright(t_a *a, t_point first, t_point second)
{
	int x;

	x = first.x;
	while (x < second.x)
	{
		print(a, x, first.y, first.color);
		x++;
	}
}

void	horizontalleft(t_a *a, t_point first, t_point second)
{
	int x;

	x = first.x;
	while (x > second.x)
	{
		print(a, x, first.y, first.color);
		x--;
	}
}

void	brasenham2(t_a *a, t_point first, t_point second)
{
	int dx;
	int dy;

	dx = second.x - first.x;
	dy = second.y - first.y;
	if ((dx < 0) && (dy > 0))
	{
		if ((dx * -1) >= dy)
			fourtho(a, first, second);
		else
			thirdo(a, first, second);
	}
	if ((dx < 0) && (dy < 0))
	{
		if (dx <= dy)
			fiftho(a, first, second);
		else
			sixtho(a, first, second);
	}
	if ((dx < 0) && (dy == 0))
		horizontalleft(a, first, second);
	if ((dx == 0) && (dy > 0))
		verticaldown(a, first, second);
	if ((dx == 0) && (dy < 0))
		verticalup(a, first, second);
}

void	brasenham(t_a *a, t_point first, t_point second)
{
	int dx;
	int dy;

	dx = second.x - first.x;
	dy = second.y - first.y;
	if ((dx > 0) && (dy > 0))
	{
		if (dx >= dy)
			firsto(a, first, second);
		else
			secondo(a, first, second);
	}
	if ((dx > 0) && (dy < 0))
	{
		if (dx >= (-1 * dy))
			eighto(a, first, second);
		else
			seveno(a, first, second);
	}
	if ((dx > 0) && (dy == 0))
		horizontalright(a, first, second);
	if (dx <= 0)
		brasenham2(a, first, second);
}
