/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:15:07 by echouvet          #+#    #+#             */
/*   Updated: 2018/01/16 17:26:22 by tgoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hooks2(int keycode, t_a *a)
{
	if (keycode == 51)
		reset(a);
	if (keycode == 88)
		moreblue(a);
	if (keycode == 85)
		lessblue(a);
	if (keycode == 87)
		moregreen(a);
	if (keycode == 84)
		lessgreen(a);
	if (keycode == 86)
		morered(a);
	if (keycode == 83)
		lessred(a);
	if (keycode == 24 || keycode == 69)
		zoommore(a);
	if (keycode == 27 || keycode == 78)
		zoomless(a);
}

int		hooks(int keycode, t_a *a)
{
	if (keycode == 53)
		exit(42);
	if (keycode == 124)
		moveright(a);
	if (keycode == 123)
		moveleft(a);
	if (keycode == 125)
		movedown(a);
	if (keycode == 126)
		moveup(a);
	if (keycode == 13)
		rot_x_up(a);
	if (keycode == 1)
		rot_x_down(a);
	if (keycode == 0)
		rot_y_left(a);
	if (keycode == 2)
		rot_y_right(a);
	if (keycode == 14)
		rot_z_1(a);
	if (keycode == 12)
		rot_z_0(a);
	hooks2(keycode, a);
	return (0);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		***data;
	t_a			a;

	if (argc != 2)
		error(42);
	mapname(argv[1]);
	fd = open(argv[1], O_RDONLY);
	a.m = mapset(fd, a.m, argv[1], 0);
	close(fd);
	data = dataset(a.m);
	a.c = coordset(a.m, data, 0, 0);
	a.p = pointset(&a);
	a.m.tx = 0;
	a.m.ty = 0;
	a.m.tz = 0;
	a.r = resetpoints(&a);
	mlx_hook(a.m.win, 2, 0, hooks, &a);
	print_window(&a);
	mlx_loop(a.m.mlx);
	return (0);
}
