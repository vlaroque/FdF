/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printgrid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:46:11 by vlaroque          #+#    #+#             */
/*   Updated: 2019/10/11 19:48:23 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "ft_segment.h"

t_point		trnspoint(t_data *d, t_ptdata ptdata)
{
	t_point		point;

	d->x = ptdata.x - d->x3d_offset;
	d->y = ptdata.y - d->y3d_offset;
	d->z = ptdata.z * d->z_proportion;

	point.color = ptdata.color;
	d->x2d = cos(d->w) * d->x - (sin(d->w) * d->y);
	point.x = d->x2d * d->zoom + d->x2d_offset;
	d->y2d = -sin(d->w) * sin(d->a) * d->x - cos(d->w) * sin(d->a) * d->y + cos(d->a) * d->z;
	point.y = -d->y2d * d->zoom + d->y2d_offset;
	return (point);
}

void	seg(t_data *data, t_ptdata one, t_ptdata two)
{
	t_seg seg;
// ATTENTION A MODIFIER !

	seg.pt0 = trnspoint(data, one);
	seg.pt1 = trnspoint(data, two);
	ft_segment(data->imgdata, seg);
}

int		printgrid_xmax_ymax(t_data *data)
{
	int i;

	i = data->tab->x_max * data->tab->y_max - 1;
	while(i >= 0)
	{
		if (i % data->tab->x_max != 0)							// tout sauf x_0
			seg(data, data->tab->table[i], data->tab->table[i - 1]);			//segment horizontal
		if ((i / data->tab->x_max) != 0)						// tout sauf y_0
			seg(data, data->tab->table[i], data->tab->table[i - data->tab->x_max]);	//segment vertical
		i--;
	}
	return (1);
}

int		printgrid_zero(t_data *data)
{
	int i;

	i = 0;
	while(i < data->tab->x_max * data->tab->y_max)
	{
		if (i % data->tab->x_max != data->tab->x_max - 1)							// tout sauf x_max
			seg(data, data->tab->table[i], data->tab->table[i + 1]);			//segment horizontal
		if ((i / data->tab->x_max) != (data->tab->y_max - 1))						// tout sauf y_max
			seg(data, data->tab->table[i], data->tab->table[i + data->tab->x_max]);	//segment vertical
		i++;
	}
	return (1);
}

int		printgrid(t_data *data)
{
	int w;
	int a;

	w = data->w_int;
	a = data->a_int;
	if ((w <= -20 && w >= -39) || (w >= 21 && w <= 40))
	{
		if((a <= 20 && a >= -20))
			printgrid_xmax_ymax(data);
		else
			printgrid_zero(data);
	}
	else
	{
		if (!((a <= 20 && a >= -20)))
			printgrid_xmax_ymax(data);
		else
			printgrid_zero(data);
	}
	return (1);
}

