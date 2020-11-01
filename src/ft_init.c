/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 20:43:06 by skale             #+#    #+#             */
/*   Updated: 2020/07/25 20:45:53 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_line		*line_init(void)
{
	t_line *line;

	if (!(line = (t_line *)ft_memalloc(sizeof(t_line))))
		exit(2);
	line->dx = 0;
	line->dy = 0;
	return (line);
}

t_dot		*dot_init(void)
{
	t_dot	*dot;

	if (!(dot = (t_dot *)ft_memalloc(sizeof(t_dot))))
		exit(2);
	dot->x = 0;
	dot->y = 0;
	dot->z = 0;
	dot->z = 0;
	dot->z0 = 0;
	dot->color = COLOR_DEFAULT_MIN;
	return (dot);
}

t_camera	*camera_init(void)
{
	t_camera *camera;

	if (!(camera = (t_camera *)ft_memalloc(sizeof(t_camera))))
		exit(2);
	camera->zoom = 10;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->offset_x = 0;
	camera->offset_y = 0;
	camera->projection = ISO;
	return (camera);
}

t_map		*map_init(void)
{
	t_map	*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		exit(2);
	map->max_xi = 0;
	map->max_yi = 0;
	map->max_z = 0;
	map->min_z = 0;
	map->mid_z = 0;
	map->sz = 1;
	map->color_min = COLOR_DEFAULT_MIN;
	map->color_max = COLOR_DEFAULT_MAX;
	map->color_mid = COLOR_DEFAULT_MID;
	return (map);
}
