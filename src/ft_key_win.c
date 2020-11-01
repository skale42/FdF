/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:59:19 by mstefani          #+#    #+#             */
/*   Updated: 2020/07/25 21:18:57 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_print_print_menu(t_mlx *mlx)
{
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5, 300, RED, "offset_x = ");
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 130, 300, RED, \
			ft_itoa(mlx->camera->offset_x));
}

void	ft_print_menu(t_mlx *mlx)
{
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5, 285, RED, "map->sz = ");
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 130, 285, RED, \
			ft_itoa(mlx->map->sz));
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5, 315, RED, "offset_y = ");
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 130, 315, RED, \
			ft_itoa(mlx->camera->offset_y));
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5, 330, RED, "maxz = ");
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 130, 330, RED, \
			ft_itoa(mlx->map->max_z));
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5, 345, RED, "minz = ");
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 130, 345, RED, \
			ft_itoa(mlx->map->min_z));
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5, 360, RED, "midz = ");
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 130, 360, RED, \
			ft_itoa(mlx->map->mid_z));
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5, 375, RED, "zoom = ");
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 130, 375, RED, \
			ft_itoa(mlx->camera->zoom));
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5, 390, RED, "PROJECTION = ");
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 130, 390, RED, \
			ft_itoa(mlx->camera->projection));
	ft_print_print_menu(mlx);
}

void	ft_set_angle(t_camera *camera, int key)
{
	if (key == Z1)
		camera->gamma += 0.05;
	if (key == Z2)
		camera->gamma -= 0.05;
	if (key == Y1)
		camera->beta += 0.05;
	if (key == Y2)
		camera->beta -= 0.05;
	if (key == X1)
		camera->alpha += 0.05;
	if (key == X2)
		camera->alpha -= 0.05;
}

void	ft_change_proj(int key, t_camera *camera)
{
	if (key == ISO_KEY)
		camera->projection = ISO;
	else
		camera->projection = PARALLEL;
}

int		ft_key_win(int key, t_mlx *mlx)
{
	if (key == ESC_KEY)
	{
		mlx_destroy_window(mlx->wnd->ptr, mlx->wnd->wnd);
		free(mlx);
		exit(0);
	}
	else if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
		ft_move(key, mlx);
	else if (key == ISO_KEY || key == PARALLEL_KEY)
		ft_change_proj(key, mlx->camera);
	else if (key == RIZE_KEY || key == FALL_KEY)
		ft_rise_or_fall(key, mlx->map);
	else if (key == X1 || key == X2 || key == Y1 || key == Y2 || \
			key == Z1 || key == Z2)
		ft_set_angle(mlx->camera, key);
	if (key == CLEAR_WINDOW)
		mlx_clear_window(mlx->wnd->ptr, mlx->wnd->wnd);
	ft_final_offset(mlx->map, mlx->camera);
	ft_rotate(mlx->map, mlx->camera);
	ft_transform(mlx->map, mlx->camera);
	ft_draw_map(mlx->wnd, mlx->map);
	ft_print_menu(mlx);
	return (0);
}
