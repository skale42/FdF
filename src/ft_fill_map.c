/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 20:48:53 by skale             #+#    #+#             */
/*   Updated: 2020/07/26 16:55:41 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*ft_nextd(char *line)
{
	while (!ft_isdigit(*line) && *line != '-' && *line != '\0' && *line != '\n')
		line++;
	return (line);
}

char	*ft_nexts(char *line)
{
	while (*line != ' ' && *line != '\0')
		line++;
	return (line);
}

int		ft_zam(char **line, int res)
{
	int sign;

	sign = 1;
	if (**line == '-')
	{
		sign = -sign;
		*line = *line + 1;
	}
	if (**line >= '0' && **line <= '9')
	{
		res *= 10;
		res = res + (**line - '0');
		*line = *line + 1;
	}
	return (sign * res);
}

int		ft_fill_line(char *line, t_dot *dots)
{
	int res;
	int x;

	x = 0;
	res = 0;
	line = ft_nextd(line);
	while (*line != '\n' && *line != '\0')
	{
		res = ft_zam(&line, res);
		if (*line == ' ' || *line == '\n' || *line == '\0')
		{
			setz(&dots[x++], res);
			line = ft_nextd(line);
			res = 0;
		}
		else if (*line == ',')
		{
			setz(&dots[x], res);
			dots[x++].color = ft_readcolor(line);
			line = ft_nexts(line);
			res = 0;
		}
		line = ft_nextd(line);
	}
	return (0);
}

t_dot	**ft_fill_map(t_map *map, char *filename)
{
	t_dot	**dots;
	char	*line;
	int		y;
	int		fd;

	y = 0;
	dots = (t_dot **)malloc(sizeof(t_dot *) * map->max_yi);
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		write(1, "Error reading\n", 14);
		exit(1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		dots[y] = (t_dot *)malloc(sizeof(t_dot) * map->max_xi);
		ft_fzero(dots[y], y, map->max_xi, map);
		ft_fill_line(line, dots[y++]);
		free(line);
	}
	line = NULL;
	ft_getmaxminmid(map, dots);
	close(fd);
	return (dots);
}
