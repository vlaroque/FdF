/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:20:45 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/27 17:14:30 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "fdf.h"
#include "ft_image.h"
#include "ft_segment.h"

int		main(void)
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_imgdata	*data;

	t_point one = {400 ,400};
	t_point two = {10, 350};
	t_seg	seg = {{400 ,400}, {10, 350}, 0x0000ff, 0xff0000};

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Une fenetre");
	data = ft_create_img(mlx_ptr, 500, 500);
	ft_segment(data, seg);
	ft_color_pix(data, 200, 200, 0xffff00);
	mlx_put_image_to_window(mlx_ptr, win_ptr, data->img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
}