/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:58:23 by mstefani          #+#    #+#             */
/*   Updated: 2020/07/26 12:28:28 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
	{
		write(1, "Need one parameter\n", 19);
		return (0);
	}
	mlx = ft_discover_map(argv[1]);
	mlx->wnd = ft_init_window();
	mlx->map->dots = ft_fill_map(mlx->map, argv[1]);
	ft_catch_order(mlx);
	ft_final_offset(mlx->map, mlx->camera);
	ft_rotate(mlx->map, mlx->camera);
	ft_transform(mlx->map, mlx->camera);
	ft_draw_map(mlx->wnd, mlx->map);
	ft_print_menu(mlx);
	mlx_loop(mlx->wnd->ptr);
	return (0);
}
