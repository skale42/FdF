/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 20:46:34 by skale             #+#    #+#             */
/*   Updated: 2020/07/25 20:47:52 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

double		ft_percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

double		ft_length(int x2, int y2, int x1, int y1)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

int			rgb_to_int(int red, int green, int blue)
{
	int		r;
	int		g;
	int		b;

	r = red & 0xFF;
	g = green & 0xFF;
	b = blue & 0xFF;
	return (r << 16 | g << 8 | b);
}

int			ft_readcolor(char *line)
{
	char	hexc[7];
	int		i;
	int		color;

	i = 0;
	while (*line != ' ' && *line != '\0' && *line != '\n' && i < 7)
	{
		if ((*line >= 48 && *line <= 57) || (ft_tolower(*line) >= 'a' \
			&& ft_tolower(*line) <= 'f'))
			hexc[i++] = *line;
		line++;
	}
	hexc[i] = '\0';
	color = ft_atoi_base(hexc, 16);
	return (color);
}

int			calculate_color(t_map *map, t_dot point)
{
	int		clr;
	int		diff;
	double	diff_pcnt;

	if (abs(point.z - map->min_z) <= abs(point.z - map->mid_z))
	{
		diff = map->mid_z - map->min_z;
		if (diff != 0)
			diff_pcnt = (point.z - map->min_z) / (double)diff;
		else
			diff_pcnt = 0.0;
		clr = get_line_color(map->color_min, map->color_mid, diff_pcnt);
		return (clr);
	}
	else
	{
		diff = map->max_z - map->mid_z;
		if (diff != 0)
			diff_pcnt = (point.z - map->mid_z) / (double)diff;
		else
			diff_pcnt = 0.0;
		clr = get_line_color(map->color_mid, map->color_max, diff_pcnt);
		return (clr);
	}
}
