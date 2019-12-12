/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_segment_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 12:38:26 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/11 14:28:03 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

	if (seg.pt0.color == seg.pt1.color)
		return (seg.pt0.color);
	if (x_max == 0)
		return (seg.pt0.color);
	color = ((((x_max - x) * (seg.pt0.color % 256)
					+ x * (seg.pt1.color % 256))) / x_max);
	color += ((((x_max - x) * ((seg.pt0.color / 256) % 256)
					+ x * ((seg.pt1.color / 256) % 256))) / x_max) * 256;
	color += ((((x_max - x) * ((seg.pt0.color / 65536) % 256)
					+ x * ((seg.pt1.color / 65536) % 256))) / x_max) * 65536;
	return (color);
}
