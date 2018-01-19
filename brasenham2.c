/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brasenham2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 08:32:04 by echouvet          #+#    #+#             */
/*   Updated: 2018/01/16 08:32:05 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	firsto(t_a *a, t_point first, t_point second)
{
	float e;
	float dx;
	float dy;
	float x;
	float y;

	dx = second.x - first.x;
	dy = second.y - first.y;
	dx *= 2;
	dy *= 2;
	e = dx;
	x = first.x;
	y = first.y;
	while (x < second.x)
	{
		print(a, x, y, first.color);
		e = e - dy;
		if (e < 0)
		{
			y++;
			e = e + dx;
		}
		x++;
	}
}

void	secondo(t_a *a, t_point first, t_point second)
{
	float e;
	float dx;
	float dy;
	float x;
	float y;

	dx = second.x - first.x;
	dy = second.y - first.y;
	dx *= 2;
	dy *= 2;
	e = dy;
	x = first.x;
	y = first.y;
	while (y < second.y)
	{
		print(a, x, y, first.color);
		e = e - dx;
		if (e < 0)
		{
			x++;
			e = e + dy;
		}
		y++;
	}
}

void	thirdo(t_a *a, t_point first, t_point second)
{
	float e;
	float dx;
	float dy;
	float x;
	float y;

	dx = second.x - first.x;
	dy = second.y - first.y;
	dx *= 2;
	dy *= 2;
	e = dy;
	x = first.x;
	y = first.y;
	while (y < second.y)
	{
		print(a, x, y, first.color);
		e = e + dx;
		if (e <= 0)
		{
			x--;
			e = e + dy;
		}
		y++;
	}
}

void	fourtho(t_a *a, t_point first, t_point second)
{
	float e;
	float dx;
	float dy;
	float x;
	float y;

	dx = second.x - first.x;
	dy = second.y - first.y;
	dx *= 2;
	dy *= 2;
	e = dx;
	x = first.x;
	y = first.y;
	while (x > second.x)
	{
		print(a, x, y, first.color);
		e = e + dy;
		if (e >= 0)
		{
			y++;
			e = e + dx;
		}
		x--;
	}
}

void	fiftho(t_a *a, t_point first, t_point second)
{
	float e;
	float dx;
	float dy;
	float x;
	float y;

	dx = second.x - first.x;
	dy = second.y - first.y;
	dx *= 2;
	dy *= 2;
	e = dx;
	x = first.x;
	y = first.y;
	while (x > second.x)
	{
		print(a, x, y, first.color);
		e = e - dy;
		if (e >= 0)
		{
			y--;
			e = e + dx;
		}
		x--;
	}
}
