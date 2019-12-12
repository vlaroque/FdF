/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:36:13 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/11 18:49:53 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

int			color_manager(char *str, int i, t_ptdata *pts, int pos)
{
	if (str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x')
	{
		i += 3;
		pts[pos].color = mini_atoi_hexa(str, &i);
	}
	else
		pts[pos].color = 0xffffff;
	return (i);
}

t_ptdata	*parsing_fill(char *str, t_ptdata *pts, int x_max, int y_max)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < y_max)
	{
		x = -1;
		while (++x < x_max)
		{
			i = space_skip(str, i);
			if (ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+')
				pts[x + (y * x_max)].z = mini_atoi(str, &i);
			i = color_manager(str, i, pts, x + (y * x_max));
			pts[x + (y * x_max)].x = x;
			pts[x + (y * x_max)].y = y;
		}
		i = space_skip(str, i);
		if (str[i] != '\n')
			return (NULL);
		i++;
		y++;
	}
	return (pts);
}

int			parser(t_data *data, char *str)
{
	int i;

	i = 0;
	data->tab.x_max = x_max(str);
	data->tab.y_max = y_max(str);
	if (!(data->tab.table = (t_ptdata *)malloc((sizeof(t_ptdata)
						* data->tab.x_max * data->tab.y_max))))
		return (0);
	if (!(data->tab.table = parsing_fill(str, data->tab.table, data->tab.x_max,
			data->tab.y_max)))
	{
		free_data(data);
		return (0);
	}
	return (1);
}
