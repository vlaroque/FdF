/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printgrid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:46:11 by vlaroque          #+#    #+#             */
/*   Updated: 2019/04/27 20:48:31 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "ft_segment.h"

t_point		trnspoint(t_ptdata data, int x_max, int y_max)
{
	t_point		point;
	t_data		d;

	d.x3d_offset = (double)x_max / 2.0 - 0.5;
	d.y3d_offset = (double)y_max / 2.0 - 0.5;
	d.x2d_offset = ((double)WIDTH) / 2.0;
	d.y2d_offset = ((double)HEIGHT) / 2.0;

	d.x = data.x - d.x3d_offset;
	d.y = data.y - d.y3d_offset;
	d.z = data.z;
	d.a = 20.0;
	d.w = 30.0;
	d.zoom = 20.0;

	point.color = data.color;
	d.x2d = cos(d.w) * d.x - (sin(d.w) * d.y);
	point.x = d.x2d * d.zoom + d.x2d_offset;
	d.y2d = -sin(d.w) * sin(d.a) * d.x - cos(d.w) * sin(d.a) * d.y + cos(d.a) * d.z;
	point.y = -d.y2d * d.zoom + d.y2d_offset; 
	return (point);
}

/*t_point		trnspoint(t_ptdata data)
{
	t_point		point;

	point.color = data.color;
	point.x = data.x * 15;
	point.y = (data.y * 15) - data.z;
	return (point);
}*/

void	seg(t_imgdata *img, t_ptdata one, t_ptdata two, t_ptstable *tab)
{
	t_seg seg;
// ATTENTION A MODIFIER !

	seg.pt0 = trnspoint(one, tab->x_max, tab->y_max);
	seg.pt1 = trnspoint(two, tab->x_max, tab->y_max);
	ft_segment(img, seg);
}

int		printgrid(t_imgdata *img, t_ptstable *tab)
{
	int i;

	i = 0;
	while(i < tab->x_max * tab->y_max)
	{
		if (i % tab->x_max != tab->x_max - 1)							// tout sauf x_max
			seg(img, tab->table[i], tab->table[i + 1], tab);			//segment horizontal
		if ((i / tab->x_max) != (tab->y_max - 1))						// tout sauf y_max
			seg(img, tab->table[i], tab->table[i + tab->x_max], tab);	//segment vertical
		i++;
	}
	return (1);
}
