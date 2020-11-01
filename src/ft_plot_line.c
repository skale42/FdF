/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plot_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:40:47 by mstefani          #+#    #+#             */
/*   Updated: 2020/07/25 20:22:46 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		ft_plot_line(int x2, int y2, t_mlx *mlx)
{
	int dx;
	int dy;
	int err;
	int e2;

	dx = ft_abs(x2 - mlx->dot->x);
	dy = ft_abs(y2 - mlx->dot->y);
	err = dx - dy;
	while ((mlx->dot->x != x2) || (mlx->dot->y != y2))
	{
		mlx_pixel_put(mlx->wnd->ptr, mlx->wnd->wnd, mlx->dot->x, \
				mlx->dot->y, mlx->dot->color);
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			mlx->dot->x += STEP(mlx->dot->x, x2);
		}
		if (e2 < dx)
		{
			err += dx;
			mlx->dot->y += STEP(mlx->dot->y, y2);
		}
	}
	return (0);
}
