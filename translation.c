/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 01:11:43 by echouvet          #+#    #+#             */
/*   Updated: 2018/01/14 01:11:44 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	moveright(t_a *a)
{
	int i;

	i = 0;
	empty(a);
	while (i < a->m.x * a->m.y)
	{
		a->c[i].x += 2;
		i++;
	}
	a->p = pointset(a);
	print_window(a);
}

void	moveleft(t_a *a)
{
	int i;

	i = 0;
	empty(a);
	while (i < a->m.x * a->m.y)
	{
		a->c[i].x -= 2;
		i++;
	}
	a->p = pointset(a);
	print_window(a);
}

void	moveup(t_a *a)
{
	int i;

	i = 0;
	empty(a);
	while (i < a->m.x * a->m.y)
	{
		a->c[i].y -= 2;
		i++;
	}
	a->p = pointset(a);
	print_window(a);
}

void	movedown(t_a *a)
{
	int i;

	i = 0;
	empty(a);
	while (i < a->m.x * a->m.y)
	{
		a->c[i].y += 2;
		i++;
	}
	a->p = pointset(a);
	print_window(a);
}
