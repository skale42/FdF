/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 20:58:07 by skale             #+#    #+#             */
/*   Updated: 2020/07/25 20:59:50 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		ft_mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->st_mouse.is_pressed && INSIDE(x, y))
	{
		ft_plot_line(x, y, mlx);
		mlx->dot->x = x;
		mlx->dot->y = y;
	}
	return (0);
}

int		ft_mouse_release(int buttom, int x, int y, t_mlx *mlx)
{
	if (buttom == 1 && INSIDE(x, y))
		mlx->st_mouse.is_pressed = 0;
	return (0);
}

int		ft_mouse_pressed(int buttom, int x, int y, t_mlx *mlx)
{
	if (buttom == 1 && INSIDE(x, y))
	{
		mlx->st_mouse.is_pressed = 1;
		mlx->dot->x = x;
		mlx->dot->y = y;
		return (1);
	}
	if (buttom == 5 && INSIDE(x, y))
	{
		if (mlx->camera->zoom < 64)
			mlx->camera->zoom = mlx->camera->zoom + 1;
	}
	if (buttom == 4 && INSIDE(x, y))
	{
		if (mlx->camera->zoom >= 1)
			mlx->camera->zoom = mlx->camera->zoom - 1;
	}
	ft_final_offset(mlx->map, mlx->camera);
	ft_rotate(mlx->map, mlx->camera);
	ft_transform(mlx->map, mlx->camera);
	ft_draw_map(mlx->wnd, mlx->map);
	ft_print_menu(mlx);
	return (0);
}
