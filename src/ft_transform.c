/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:56:33 by mstefani          #+#    #+#             */
/*   Updated: 2020/07/25 20:57:18 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	ft_offset(t_map *mp, t_camera *cam)
{
	int y;
	int x;

	y = 0;
	while (y < mp->max_yi)
	{
		x = 0;
		while (x < mp->max_xi)
		{
			mp->dots[y][x].x = mp->dots[y][x].x + cam->offset_x;
			mp->dots[y][x].y = mp->dots[y][x].y + cam->offset_y;
			x++;
		}
		y++;
	}
}

void	ft_transform(t_map *mp, t_camera *cam)
{
	int y;
	int x;

	y = 0;
	if (cam->projection == ISO)
	{
		while (y < mp->max_yi)
		{
			x = 0;
			while (x < mp->max_xi)
			{
				ft_iso(&mp->dots[y][x].x, &mp->dots[y][x].y, mp->dots[y][x].z);
				mp->dots[y][x].x = mp->dots[y][x].x + cam->offset_x;
				mp->dots[y][x].y = mp->dots[y][x].y + cam->offset_y;
				x++;
			}
			y++;
		}
	}
	else
		ft_offset(mp, cam);
}
