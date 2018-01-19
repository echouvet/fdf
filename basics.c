/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 23:30:03 by echouvet          #+#    #+#             */
/*   Updated: 2018/01/09 23:30:04 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset(t_a *a)
{
	int	i;

	i = 0;
	empty(a);
	while (i < a->m.x * a->m.y)
	{
		a->c[i].x = a->r[i].x;
		a->c[i].y = a->r[i].y;
		a->c[i].z = a->r[i].z;
		a->c[i].color = a->r[i].color;
		i++;
	}
	a->m.tx = 0;
	a->m.ty = 0;
	a->m.tz = 0;
	a->m.between_y = (1000 / a->m.y) / 1.5;
	a->m.between_x = (1500 / a->m.x) / 1.5;
	a->p = pointset(a);
	print_window(a);
}

t_r		*resetpoints(t_a *a)
{
	int	i;
	t_r	*r;

	i = 0;
	if (!(r = (t_r*)malloc(sizeof(t_r) * (a->m.x * a->m.y))))
		error(66);
	while (i < a->m.x * a->m.y)
	{
		r[i].x = a->c[i].x;
		r[i].y = a->c[i].y;
		r[i].z = a->c[i].z;
		r[i].color = a->c[i].color;
		i++;
	}
	return (r);
}

void	error(int i)
{
	if (i == 50)
		ft_putendl("Error: Bad file");
	if (i == 66)
		ft_putendl("Error: Malloc fail");
	if (i == 42)
		ft_putendl("Error");
	exit(42);
}

int		tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (i);
}

int		base16(char *nbr, int x, int j)
{
	char	*hex;
	char	*hexmin;
	int		i;
	int		ans;

	i = ft_strlen(nbr) - 1;
	while (++i < 6)
		nbr = ft_strjoin("0", nbr);
	ans = 0;
	hex = ft_strdup("0123456789ABCDEF");
	hexmin = ft_strdup("0123456789abcdef");
	while (--i >= 0)
	{
		x = 0;
		while (hexmin[x] != nbr[i] && (hex[x] != nbr[i]) && hex[x])
			x++;
		if (i == 5)
			ans = ans + x;
		ans = (pow(16, j) * x) + ans;
		j++;
	}
	free(hex);
	free(hexmin);
	ans = ans / 16;
	return (ans);
}
