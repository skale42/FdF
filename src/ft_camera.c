/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:53:06 by skale             #+#    #+#             */
/*   Updated: 2020/07/25 20:18:07 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_move(int key, t_mlx *mlx)
{
	if (key == LEFT)
		mlx->camera->offset_x -= 5;
	else if (key == RIGHT)
		mlx->camera->offset_x += 5;
	else if (key == UP)
		mlx->camera->offset_y -= 5;
	else
		mlx->camera->offset_y += 5;
}

void	ft_rise_or_fall(int key, t_map *map)
{
	if (key == RIZE_KEY)
		map->sz += STEP_Z;
	else if (map->sz > 0.2)
		map->sz -= STEP_Z;
}
