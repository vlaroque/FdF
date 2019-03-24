/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_segment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:43:11 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/24 22:10:16 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_image.h"
#include "fdf.h"

int			ft_segt_landing(t_imgdata *data, int x, int y, int i, int j)
{
	int e;
	int e1;
	int e2;

	e = -(i - x);
	e1 = (j - y) * 2;
	e2 = -(i - x) * 2;
	while (x <= i)
	{
		ft_color_pix(data, x, y, 0xffffff);
		e = e + e1;
		if (e >= 0)
		{
			e = e + e2;
			y++;
		}
		x++;
	}
	return (0);
}

int			ft_segt_fall(t_imgdata *data, int x, int y, int i, int j)
{
	int e;
	int e1;
	int e2;

	e = -(j - y);
	e1 = (i - x) * 2;
	e2 = -(j - y) * 2;
	while (y <= j)
	{
		ft_color_pix(data, x, y, 0xffffff);
		e = e + e1;
		if (e >= 0)
		{
			e = e + e2;
			x++;
		}
		y++;
	}
	return (0);
}

int			ft_segt_rocket(t_imgdata *data, int x, int y, int i, int j)
{
	int e;
	int e1;
	int e2;

	e = (j - y);
	e1 = (i - x) * 2;
	e2 = (j - y) * 2;
	while (y >= j)
	{
		ft_color_pix(data, x, y, 0xffffff);
		e = e + e1;
		if (e >= 0)
		{
			e = e + e2;
			x++;
		}
		y--;
	}
	return (0);
}

int			ft_segt_plane(t_imgdata *data, int x, int y, int i, int j)
{
	int e;
	int e1;
	int e2;

	e = -(i - x);
	e1 = -(j - y) * 2;
	e2 = -(i - x) * 2;
	while (x <= i)
	{
		ft_color_pix(data, x, y, 0xffffff);
		e = e + e1;
		if (e >= 0)
		{
			e = e + e2;
			y--;
		}
		x++;
	}
	return (0);
}

int			ft_segment(t_imgdata *data, t_point one, t_point two)
{
	t_point save;

	if (one.x > two.x)
	{
		save = one;
		one = two;
		two = save;
	}
	if (one.y <= two.y)
	{
		if (two.y - one.y <= two.x - one.x)
			ft_segt_landing(data, one.x, one.y, two.x, two.y);
		else
			ft_segt_fall(data, one.x, one.y, two.x, two.y);
	}
	else
	{
		if ( -(two.y - one.y) <= two.x - one.x)
			ft_segt_plane(data, one.x, one.y, two.x, two.y);
		else
			ft_segt_rocket(data, one.x, one.y, two.x, two.y);
	}
	return (0);
}