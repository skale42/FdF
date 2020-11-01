/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:11:10 by mstefani          #+#    #+#             */
/*   Updated: 2020/07/25 20:29:01 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int				get_pixel_color(double start, double end, double current)
{
	return ((int)start * (1.0 - current) + (end * current));
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

int				get_line_color(int color1, int color2, double color_grad)
{
	int			red;
	int			green;
	int			blue;

	if (color1 == color2)
		return (color1);
	red = (int)get_pixel_color(((color1 >> 16) & 0xFF), \
			((color2 >> 16) & 0xFF), color_grad);
	green = (int)get_pixel_color(((color1 >> 8) & 0xFF), \
			((color2 >> 8) & 0xFF), color_grad);
	blue = (int)get_pixel_color((color1 & 0xFF), (color2 & 0xFF), color_grad);
	return ((red << 16) | (green << 8) | blue);
}

double			get_percentage_color(double start, double end, double current)
{
	double		placement;
	double		distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

void			draw_line(t_wnd *elem, t_dot p0, t_dot p1)
{
	t_line		line;

	line = set_line(p0, p1);
	while (1)
	{
		(line.dx > line.dy) ? \
			(line.color_grad = get_percentage_color(p0.x, p1.x, line.x0)) : \
			(line.color_grad = get_percentage_color(p0.y, p1.y, line.y0));
		line.color = get_line_color(p0.color, p1.color, line.color_grad);
		ft_put_pixel(line.x0 + WX / 2, line.y0 + WY / 2, line.color, elem);
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break ;
		line.error2 = line.error * 2;
		if (line.error2 > -line.dy)
		{
			line.error -= line.dy;
			line.x0 += line.sx;
		}
		if (line.error2 < line.dx)
		{
			line.error += line.dx;
			line.y0 += line.sy;
		}
	}
}
