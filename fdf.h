/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:15:50 by echouvet          #+#    #+#             */
/*   Updated: 2018/01/09 15:15:51 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct	s_map
{
	char		**tab;
	char		*name;
	void		*img;
	void		*mlx;
	void		*win;
	int			bpp;
	int			s_l;
	int			edn;
	int			x;
	int			y;
	int			*pixels;
	int			starting_y;
	int			starting_x;
	int			between_y;
	int			between_x;
	float		tx;
	float		ty;
	float		tz;
}				t_map;

typedef	struct	s_coord
{
	int		color;
	float	x;
	float	y;
	float	z;
}				t_coord;

typedef	struct	s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}				t_color;

typedef	struct	s_r
{
	int		color;
	float	x;
	float	y;
	float	z;
}				t_r;

typedef	struct	s_point
{
	int		color;
	float	x;
	float	y;
	float	z;
}				t_point;

typedef	struct	s_a
{
	t_map	m;
	t_coord	*c;
	t_point	*p;
	t_r		*r;
}				t_a;

void			mapname(char *name);
t_map			mapset(int fd, t_map map, char *name, int tmp);
char			***dataset(t_map map);
t_coord			*coordset(t_map map, char ***data, int i, int k);
t_point			*pointset(t_a *a);
int				base16(char *nbr, int x, int j);
void			error(int i);
t_r				*resetpoints(t_a *a);
void			reset(t_a *a);
int				tablen(char **tab);
void			print_window(t_a *a);
void			empty(t_a *a);
void			moveright(t_a *a);
void			moveleft(t_a *a);
void			moveup(t_a *a);
void			movedown(t_a *a);
void			rot_y_left(t_a *a);
void			rot_y_right(t_a *a);
void			rot_x_up(t_a *a);
void			rot_x_down(t_a *a);
void			brasenham(t_a *a, t_point first, t_point second);
void			print(t_a *a, int x, int y, int color);
void			firsto(t_a *a, t_point first, t_point second);
void			secondo(t_a *a, t_point first, t_point second);
void			thirdo(t_a *a, t_point first, t_point second);
void			fourtho(t_a *a, t_point first, t_point second);
void			fiftho(t_a *a, t_point first, t_point second);
void			sixtho(t_a *a, t_point first, t_point second);
void			seveno(t_a *a, t_point first, t_point second);
void			eighto(t_a *a, t_point first, t_point second);
void			verticalup(t_a *a, t_point first, t_point second);
void			verticaldown(t_a *a, t_point first, t_point second);
void			moregreen(t_a *a);
void			lessgreen(t_a *a);
void			moreblue(t_a *a);
void			lessblue(t_a *a);
void			morered(t_a *a);
void			lessred(t_a *a);
void			zoommore(t_a *a);
void			zoomless(t_a *a);

#endif
