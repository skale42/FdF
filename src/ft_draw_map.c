/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:13:44 by mstefani          #+#    #+#             */
/*   Updated: 2020/07/25 20:56:22 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void		draw_background(t_wnd *wnd)
{
	int			*image;
	int			i;

	ft_bzero(wnd->data_addr, WX * WY * (wnd->bit_per_pixel / 8));
	image = (int *)(wnd->data_addr);
	i = 0;
	while (i < (WY * WX))
	{
		image[i] = BACKGROUND;
		i++;
	}
}

static t_line	set_line(t_dot point_0, t_dot point_1)
{
	t_line		line;

	line.x0 = (int)point_0.x;
	line.y0 = (int)point_0.y;
	line.x1 = (int)point_1.x;
	line.y1 = (int)point_1.y;
	line.dx = ft_abs(line.x1 - line.x0);
	line.dy = ft_abs(line.y1 - line.y0);
	line.sx = line.x0 < line.x1 ? 1 : -1;
	line.sy = line.y0 < line.y1 ? 1 : -1;
	line.error = line.dx - line.dy;
	line.color_grad = 0.0;
	return (line);
}

void			ft_draw_map(t_wnd *wnd, t_map *map)
{
	int			ix;
	int			iy;

	iy = 0;
	draw_background(wnd);
	while (iy < map->max_yi)
	{
		ix = 0;
		while (ix < map->max_xi)
		{
			if (ix < map->max_xi - 1)
				draw_line(wnd, map->dots[iy][ix], map->dots[iy][ix + 1]);
			if (iy < map->max_yi - 1)
				draw_line(wnd, map->dots[iy][ix], map->dots[iy + 1][ix]);
			ix++;
		}
		iy++;
	}
	if (map->max_xi == 1 && map->max_yi == 1)
		ft_put_pixel(map->dots[0][0].x + WX / 2, \
					map->dots[0][0].y + WY / 2, map->dots[0][0].color, wnd);
	mlx_put_image_to_window(wnd->ptr, wnd->wnd, wnd->img, 0, 0);
}
