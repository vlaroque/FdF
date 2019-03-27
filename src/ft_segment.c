/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_segment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:43:11 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/27 17:20:19 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_image.h"
#include "fdf.h"
int			ft_what_color(int x, int x_max, t_seg seg)
{
	int color;

	color = ((x * (seg.clr0 % 256) + (x_max - x) * (seg.clr1 % 256)) / x_max)
		+ ((x * ((seg.clr0 / 256) % 256) + (x_max - x) * ((seg.clr1 / 256) % 256)) / x_max) * 256
		+ ((x * ((seg.clr0 / 65536) % 256) + (x_max - x) * ((seg.clr1 / 65536) % 256)) / x_max) * 65536;
	return (color);
}

int			ft_segt_landing(t_imgdata *data, t_seg seg)
{
	int e;
	int e1;
	int e2;
	int x_save;

	x_save = seg.pt0.x;
	e = -(seg.pt1.x - seg.pt0.x);
	e1 = (seg.pt1.y - seg.pt0.y) * 2;
	e2 = -(seg.pt1.x - seg.pt0.x) * 2;
	while (seg.pt0.x <= seg.pt1.x)
	{
		ft_color_pix(data, seg.pt0.x, seg.pt0.y,
			ft_what_color(seg.pt0.x - x_save, seg.pt1.x - x_save, seg));
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
	int x_save;

	x_save = seg.pt0.x;
	e = -(seg.pt1.y - seg.pt0.y);
	e1 = (seg.pt1.x - seg.pt0.x) * 2;
	e2 = -(seg.pt1.y - seg.pt0.y) * 2;
	while (seg.pt0.y <= seg.pt1.y)
	{
		ft_color_pix(data, seg.pt0.x, seg.pt0.y, ft_what_color(seg.pt0.x - x_save, seg.pt1.x - x_save, seg));
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
	int x_save;

	x_save = seg.pt0.x;
	e = (seg.pt1.y - seg.pt0.y);
	e1 = (seg.pt1.x - seg.pt0.x) * 2;
	e2 = (seg.pt1.y - seg.pt0.y) * 2;
	while (seg.pt0.y >= seg.pt1.y)
	{
		ft_color_pix(data, seg.pt0.x, seg.pt0.y, ft_what_color(seg.pt0.x - x_save, seg.pt1.x - x_save, seg));
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
		ft_color_pix(data, seg.pt0.x, seg.pt0.y, ft_what_color(seg.pt0.x - x_save, seg.pt1.x - x_save, seg));
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
	int		colorsave;

	if (seg.pt0.x > seg.pt1.x)
	{
		save = seg.pt0;
		seg.pt0 = seg.pt1;
		seg.pt1 = save;
		colorsave = seg.clr0;
		seg.clr0 = seg.clr1;
		seg.clr1 = colorsave;
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
