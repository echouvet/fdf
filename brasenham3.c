/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brasenham3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 08:32:13 by echouvet          #+#    #+#             */
/*   Updated: 2018/01/16 08:32:14 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	sixtho(t_a *a, t_point first, t_point second)
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
	while (y > second.y)
	{
		print(a, x, y, first.color);
		e = e - dx;
		if (e >= 0)
		{
			x--;
			e = e + dy;
		}
		y--;
	}
}

void	seveno(t_a *a, t_point first, t_point second)
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
	while (y > second.y)
	{
		print(a, x, y, first.color);
		e = e + dx;
		if (e > 0)
		{
			x++;
			e = e + dy;
		}
		y--;
	}
}

void	eighto(t_a *a, t_point first, t_point second)
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
		e = e + dy;
		if (e < 0)
		{
			y--;
			e = e + dx;
		}
		x++;
	}
}

void	verticaldown(t_a *a, t_point first, t_point second)
{
	int y;

	y = first.y;
	while (y < second.y)
	{
		print(a, first.x, y, first.color);
		y++;
	}
}

void	verticalup(t_a *a, t_point first, t_point second)
{
	int y;

	y = first.y;
	while (y > second.y)
	{
		print(a, first.x, y, first.color);
		y--;
	}
}
