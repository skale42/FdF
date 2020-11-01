/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_discover_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:23:45 by mstefani          #+#    #+#             */
/*   Updated: 2020/07/26 12:53:15 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		setz(t_dot *dot, int z)
{
	if (z > INT_MIN / 8 && z < INT_MAX / 8)
	{
		dot->z0 = z;
		dot->z = z;
	}
	else
	{
		write(1, "wrong file\n", 11);
		exit(6);
	}
}

void		setcolor(t_map *map, t_dot **dots)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->max_yi)
	{
		x = 0;
		while (x < map->max_xi)
		{
			if (dots[y][x].color == map->color_min)
				dots[y][x].color = calculate_color(map, dots[y][x]);
			x++;
		}
		y++;
	}
}

void		ft_getmaxminmid(t_map *map, t_dot **dots)
{
	int		x;
	int		y;

	y = 0;
	map->max_z = 0;
	map->min_z = 0;
	while (y < map->max_yi)
	{
		x = 0;
		while (x < map->max_xi)
		{
			if (dots[y][x].z > map->max_z)
				map->max_z = dots[y][x].z;
			if (dots[y][x].z < map->min_z)
				map->min_z = dots[y][x].z;
			x++;
		}
		y++;
	}
	map->mid_z = (map->max_z - map->min_z) / 2;
	setcolor(map, dots);
}

t_mlx		*ft_discover_map(char *filename)
{
	int		fd;
	char	*line;
	t_mlx	*mlx;

	if (!(mlx = malloc(sizeof(t_mlx))))
		exit(2);
	ft_set_constants(mlx);
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		write(1, "Error reading\n", 14);
		exit(1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		ft_calc_digits(line, mlx->map);
		mlx->map->max_yi++;
		free(line);
	}
	close(fd);
	line = NULL;
	if (mlx->map->max_xi == 0)
		exit(3);
	return (mlx);
}
