/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:22:52 by echouvet          #+#    #+#             */
/*   Updated: 2018/01/09 14:22:53 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		mapname(char *name)
{
	int i;

	i = ft_strlen(name);
	if (name[i - 1] != 'f' || name[i - 2] != 'd' || name[i - 3] != 'f' ||
		name[i - 4] != '.')
		error(50);
}

char		**fileread(const int fd)
{
	int		size;
	char	buffer[4097];
	char	*str;
	char	**tab;
	char	*tmp;

	if (!(str = ft_strdup("")))
		error(66);
	size = 42;
	while (size > 0)
	{
		if (((size = read(fd, buffer, 4096)) && size == -1))
			error(50);
		buffer[size] = 0;
		if (!(tmp = ft_strjoin(str, buffer)))
			error(66);
		free(str);
		if (!(str = ft_strdup(tmp)))
			error(66);
		free(tmp);
	}
	if (!(tab = ft_splitstr(str, '\n')))
		error(66);
	free(str);
	return (tab);
}

t_coord		*coordset(t_map map, char ***data, int i, int k)
{
	t_coord *coord;
	int		x;
	int		j;

	if (!(coord = (t_coord*)malloc(sizeof(t_coord) * (map.x * map.y))))
		error(66);
	while (i != (map.x * map.y))
	{
		j = 0;
		while (j != map.x)
		{
			x = -1;
			coord[i].x = j - (map.x / 2);
			coord[i].y = k - (map.y / 2);
			coord[i].color = 16777215;
			while (data[k][j][++x])
				if (data[k][j][x] == ',')
					coord[i].color = (base16((data[k][j] + x + 3), 0, 1));
			coord[i].z = ft_atoi(data[k][j]);
			j++;
			i++;
		}
		k++;
	}
	return (coord);
}

char		***dataset(t_map map)
{
	char	***data;
	int		i;

	i = 0;
	if (!(data = (char***)malloc(sizeof(char**) * map.y)))
		error(66);
	while (i != map.y)
	{
		if (!(data[i] = ft_strsplit(map.tab[i], ' ')))
			error(66);
		i++;
	}
	return (data);
}

t_map		mapset(int fd, t_map map, char *name, int tmp)
{
	char	*pixels;

	map.x = 0;
	map.y = -1;
	map.mlx = mlx_init();
	map.name = name;
	map.img = mlx_new_image(map.mlx, 1500, 1000);
	map.win = mlx_new_window(map.mlx, 1500, 1000, map.name);
	pixels = mlx_get_data_addr(map.img, &map.bpp, &map.s_l, &map.edn);
	map.pixels = (int*)pixels;
	map.tab = fileread(fd);
	if (map.tab[0] == NULL)
		error(50);
	while (map.tab[++map.y])
	{
		if ((!(tmp = tablen(ft_strsplit(map.tab[map.y], ' ')))) ||
			(map.x != 0 && tmp != map.x))
			error(50);
		map.x = tmp;
	}
	map.starting_y = 500 - (((1000 / map.y) / 3) * map.y / 4);
	map.starting_x = 750 - (((1500 / map.x) / 3) * map.x / 4);
	map.between_y = (1000 / map.y) / 1.5;
	map.between_x = (1500 / map.x) / 1.5;
	return (map);
}
