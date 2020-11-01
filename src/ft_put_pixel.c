/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:05:52 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/27 17:05:57 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_put_pixel(int x, int y, int color, t_wnd *wnd)
{
	int i;

	if (x >= 0 && x < WX && y >= 0 && y < WY)
	{
		i = x * wnd->bit_per_pixel / 8 + wnd->size_line * y;
		wnd->data_addr[i + 0] = (color) & 0xFF;
		wnd->data_addr[i + 1] = (color >> 8) & 0xFF;
		wnd->data_addr[i + 2] = (color >> 16) & 0xFF;
		wnd->data_addr[i + 3] = 0;
	}
}
