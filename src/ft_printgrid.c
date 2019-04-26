/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printgrid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:46:11 by vlaroque          #+#    #+#             */
/*   Updated: 2019/04/26 19:41:47 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "ft_segment.h"

t_point		trnspoint(t_ptdata data)
{
	t_point		point;
	double		x;
	double		y;
	double		z;
	double		a;
	double		w;
	double		x2d;
	double		y2d;

	x = data.x;
	y = data.y;
	z = data.z;
	a = 20.0;
	w = 30.0;
	point.color = data.color;
	x2d = cos(w) * x - (sin(w) * y);
	point.x = x2d * 10.0;
	y2d = -sin(w) * sin(a) * x - cos(w) * sin(a) * y + cos(a) * z;
	point.y = y2d * 10.0; 
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

void	seg(t_imgdata *img, t_ptdata one, t_ptdata two)
{
	t_seg seg;
// ATTENTION A MODIFIER !

	seg.pt0 = trnspoint(one);
	seg.pt1 = trnspoint(two);
	ft_segment(img, seg);
}

int		printgrid(t_imgdata *img, t_ptstable *tab)
{
	int i;

	i = 0;
	while(i < tab->x_max * tab->y_max)
	{
		if (i % tab->x_max != tab->x_max - 1)						// tout sauf x_max
			seg(img, tab->table[i], tab->table[i + 1]);				//segment horizontal
		if ((i / tab->x_max) != (tab->y_max - 1))					// tout sauf y_max
			seg(img, tab->table[i], tab->table[i + tab->x_max]);	//segment vertical
		i++;
	}
	return (1);
}
