/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:20:45 by vlaroque          #+#    #+#             */
/*   Updated: 2019/10/11 20:43:03 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fdf.h"
#include "ft_image.h"
#include "ft_segment.h"
#include "ft_readfile.h"
#include "ft_parsing.h"

void	erase_img(int *imgbuff)
{
	int i;
	int len;

	len = HEIGHT * WIDTH;
	i = 0;
	while (i < len)
		imgbuff[i++] = 0;
}

int		print_new_img(t_data *data)
{
	erase_img((int *)data->imgdata->img_content);
	printgrid(data);
	return (0);
}

double	pirotation(int *var, int op)
{
	int max;
	int min;

	max = 40;
	min = -39;
	if (op > 0)
	{
		if (*var == max)
			*var = min;
		else
			*var += 1;
	}
	else if (op < 0)
	{
		if (*var == min)
			*var = max;
		else
			*var -= 1;
	}
	return (((double)*var) / 40.0 * M_PI);
}

int		loop_hook(void *nothing)
{
	return ((int)nothing);
}

int		key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		exit (1);
	else if (keycode == 69) // +
		data->zoom += 1.0;
	else if (keycode == 78) // -
		data->zoom -= 1.0;
	else if (keycode == 84) // 2
		data->a = pirotation(&(data->a_int), 1);
	else if (keycode == 91) // 8
		data->a = pirotation(&(data->a_int), -1);
	else if (keycode == 86) // 4
		data->w = pirotation(&(data->w_int), 1);
	else if (keycode == 88) // 6
		data->w = pirotation(&(data->w_int), -1);
	else if (keycode == 89) // 7
		data->z_proportion += 0.1;
	else if (keycode == 83) // 1
		data->z_proportion -= 0.1;
	else if (keycode == 126) // ^
		data->y2d_offset += 1.0;
	else if (keycode == 125) // v
		data->y2d_offset -= 1.0;
	else if (keycode == 123) // <
		data->x2d_offset += 1.0;
	else if (keycode == 124) // >
		data->x2d_offset -= 1.0;

	print_new_img(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->imgdata->img_ptr, 0, 0);
	return (0);
}

int		main(int ac, char **av)
{
	char		*path;
	char		*str;
	t_data		data;
	(void)ac;

	path = av[1];
	str = ft_readfile(path);
	if(!(data.tab = parser(str)))
		return (0);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Une fenetre");
	data.imgdata = ft_create_img(data.mlx_ptr, WIDTH, HEIGHT);

	data.a_int = 0;
	data.w_int = 0;
	data.zoom = 20.0;
	data.z_proportion = 1.0;

	data.x3d_offset = (double)data.tab->x_max / 2.0 - 0.5;
	data.y3d_offset = (double)data.tab->y_max / 2.0 - 0.5;
	data.x2d_offset = ((double)WIDTH) / 2.0;
	data.y2d_offset = ((double)HEIGHT) / 2.0;

	printgrid(&data);
	//mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.imgdata->img_ptr, 0, 0);
	mlx_hook(data.win_ptr, 2, 0, &key_hook, (void *)&data);
	//mlx_key_hook(data.win_ptr, &(key_hook), (void *)&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
