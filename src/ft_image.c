/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:13:08 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/11 14:26:40 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

t_imgdata	*ft_create_img(void *mlx_ptr, int width, int height)
{
	t_imgdata	*idata;

	if (!(idata = (t_imgdata *)malloc(sizeof(t_imgdata))))
		return (NULL);
	idata->width = width;
	idata->height = height;
	idata->img_ptr = mlx_new_image(mlx_ptr, width, height);
	idata->img_content = mlx_get_data_addr(idata->img_ptr,
			&(idata->bits_in_pix), &(idata->size_line), &(idata->endian));
	return (idata);
}

int			ft_color_pix(t_imgdata *data, int x, int y, int color)
{
	int		dist;
	int		*pix;

	dist = y * data->size_line + (x * (data->bits_in_pix / 8));
	dist = dist / 4;
	pix = (int *)data->img_content;
	pix[dist] = color;
	return (0);
}
