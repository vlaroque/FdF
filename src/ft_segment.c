/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_segment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:43:11 by vlaroque          #+#    #+#             */
/*   Updated: 2019/04/27 18:11:27 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_image.h"

int			ft_isinwin(int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (x >= WIDTH || y >= HEIGHT)
		return (0);
	return (1);
}

int			ft_what_color(int x, int x_max, t_seg seg)
{
	int color;

	if (x_max == 0)
		return(seg.pt0.color);
	color = ((((x_max - x) * (seg.pt0.color % 256)  + x * (seg.pt1.color % 256))) / x_max);
	color += ((((x_max - x) * ((seg.pt0.color / 256) % 256) + x * ((seg.pt1.color / 256) % 256))) / x_max) * 256;
	color += ((((x_max - x) * ((seg.pt0.color / 65536) % 256) + x * ((seg.pt1.color / 65536) % 256))) / x_max) * 65536;
	//color = 0xFFFFFF;
	return (color);
}

int			ft_segt_landing(t_imgdata *data, t_seg seg)
{
	int e;
	int e1;
	int e2;
	int init;

	init = seg.pt0.x;
	e = -(seg.pt1.x - seg.pt0.x);
	e1 = (seg.pt1.y - seg.pt0.y) * 2;
	e2 = -(seg.pt1.x - seg.pt0.x) * 2;
	while (seg.pt0.x <= seg.pt1.x)
	{
		if(ft_isinwin(seg.pt0.x, seg.pt0.y))
			ft_color_pix(data, seg.pt0.x, seg.pt0.y,
				ft_what_color(seg.pt0.x - init, seg.pt1.x - init, seg));
		e = e + e1;
		if (e >= 0)
		{
			e = e + e2;
			seg.pt0.y++;
		}
		seg.pt0.x++;
	}
	return (0);
}

int			ft_segt_fall(t_imgdata *data, t_seg seg)
{
	int e;
	int e1;
	int e2;
	int y_save;

	y_save = seg.pt0.y;
	e = -(seg.pt1.y - seg.pt0.y);
	e1 = (seg.pt1.x - seg.pt0.x) * 2;
	e2 = -(seg.pt1.y - seg.pt0.y) * 2;
	while (seg.pt0.y <= seg.pt1.y)
	{
		if(ft_isinwin(seg.pt0.x, seg.pt0.y))
			ft_color_pix(data, seg.pt0.x, seg.pt0.y,
					ft_what_color(seg.pt0.y - y_save, seg.pt1.y - y_save, seg));
		e = e + e1;
		if (e >= 0)
		{
			e = e + e2;
			seg.pt0.x++;
		}
		seg.pt0.y++;
	}
	return (0);
}

int			ft_segt_rocket(t_imgdata *data, t_seg seg)
{
	int e;
	int e1;
	int e2;
	int y_save;

	y_save = seg.pt0.y;
	e = (seg.pt1.y - seg.pt0.y);
	e1 = (seg.pt1.x - seg.pt0.x) * 2;
	e2 = (seg.pt1.y - seg.pt0.y) * 2;
	while (seg.pt0.y >= seg.pt1.y)
	{
		if(ft_isinwin(seg.pt0.x, seg.pt0.y))
			ft_color_pix(data, seg.pt0.x, seg.pt0.y, 
					ft_what_color((seg.pt0.y - y_save), seg.pt1.y - y_save, seg));
		e = e + e1;
		if (e >= 0)
		{
			e = e + e2;
			seg.pt0.x++;
		}
		seg.pt0.y--;
	}
	return (0);
}

int			ft_segt_plane(t_imgdata *data, t_seg seg)
{
	int e;
	int e1;
	int e2;
	int x_save;

	x_save = seg.pt0.x;
	e = -(seg.pt1.x - seg.pt0.x);
	e1 = -(seg.pt1.y - seg.pt0.y) * 2;
	e2 = -(seg.pt1.x - seg.pt0.x) * 2;
	while (seg.pt0.x <= seg.pt1.x)
	{
		if(ft_isinwin(seg.pt0.x, seg.pt0.y))
			ft_color_pix(data, seg.pt0.x, seg.pt0.y,
					ft_what_color(seg.pt0.x - x_save, seg.pt1.x - x_save, seg));
		e = e + e1;
		if (e >= 0)
		{
			e = e + e2;
			seg.pt0.y--;
		}
		seg.pt0.x++;
	}
	return (0);
}

int			ft_segment(t_imgdata *data, t_seg seg)
{
	t_point save;
	
	if (seg.pt0.x > seg.pt1.x)
	{
		save = seg.pt0;
		seg.pt0 = seg.pt1;
		seg.pt1 = save;
	}
	if (seg.pt0.y <= seg.pt1.y)
	{
		if (seg.pt1.y - seg.pt0.y <= seg.pt1.x - seg.pt0.x)
			ft_segt_landing(data, seg);
		else
			ft_segt_fall(data, seg);
	}
	else
	{
		if ( -(seg.pt1.y - seg.pt0.y) <= seg.pt1.x - seg.pt0.x)
			ft_segt_plane(data, seg);
		else
			ft_segt_rocket(data, seg);
	}
	return (0);
}
