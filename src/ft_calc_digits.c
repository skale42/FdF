/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_digits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:27:01 by mstefani          #+#    #+#             */
/*   Updated: 2020/07/26 16:52:15 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*ft_goto_next_digit(char *line)
{
	while (!ft_isdigit(*line) && *line != '\0' && *line != '\n')
		line++;
	return (line);
}

int		ft_calc_digits(char *line, t_map *map)
{
	int num;

	num = 1;
	line = ft_goto_next_digit(line);
	while (*line != '\n' && *line != '\0')
	{
		if (*line != ' ')
			line++;
		else
		{
			line = ft_goto_next_digit(line);
			num++;
		}
	}
	if (map->max_xi < num)
		map->max_xi = num;
	return (num);
}
