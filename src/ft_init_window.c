/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_veryfy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:19:06 by mstefani          #+#    #+#             */
/*   Updated: 2020/07/25 21:13:36 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_wnd		*ft_init_window(void)
{
	t_wnd	*wnd;

	if (!(wnd = (t_wnd*)ft_memalloc(sizeof(t_wnd))))
		exit(2);
	if (!(wnd->ptr = mlx_init()))
		exit(1);
	if (!(wnd->wnd = mlx_new_window(wnd->ptr, WX, WY, "Skale&Mstefani_FdF")))
		exit(1);
	if (!(wnd->img = mlx_new_image(wnd->ptr, WX, WY)))
		exit(1);
	wnd->data_addr = mlx_get_data_addr(wnd->img, &wnd->bit_per_pixel, \
			&wnd->size_line, &wnd->endian);
	return (wnd);
}
