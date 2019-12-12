/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 05:55:20 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/11 19:03:01 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

int		iso_mode(t_data *data)
{
	data->zoom = 20.0;
	data->z_proportion = 1.0;
	data->mode = 2;
	data->w = 0.785398;
	data->a = 0.610865238;
	return (0);
}

int		par_mode(t_data *data)
{
	data->zoom = 20.0;
	data->z_proportion = 1.0;
	data->mode = 1;
	data->w_int = 0;
	data->a_int = 10;
	data->w = pirotation(&(data->w_int), 0);
	data->a = pirotation(&(data->a_int), 0);
	return (0);
}

/*
** keycodes 34 = i | 35 = p | 53 = esc
** 84 = 2 | 91 = 8 | 86 = 4 | 88 = 6 | 89 = 7 | 83 = 1
** 69 = + | 78 = - | 126 = ^ | 125 = v | 123 = < | 124 = >
*/

int		par_instructions(t_data *data, int keycode)
{
	if (data->mode != 1)
		return (0);
	if (keycode == 84)
		data->a = pirotation(&(data->a_int), 1);
	else if (keycode == 91)
		data->a = pirotation(&(data->a_int), -1);
	else if (keycode == 86)
		data->w = pirotation(&(data->w_int), 1);
	else if (keycode == 88)
		data->w = pirotation(&(data->w_int), -1);
	else if (keycode == 89)
		data->z_proportion += 0.1;
	else if (keycode == 83)
		data->z_proportion -= 0.1;
	return (0);
}

int		gen_instructions(t_data *data, int keycode)
{
	if (keycode == 69 && data->zoom < 10000.0)
		data->zoom *= 10.0 / 9.0;
	else if (keycode == 78 && data->zoom > 0.00001)
		data->zoom *= 9.0 / 10.0;
	else if (keycode == 126)
		data->y2d_offset += 5.0;
	else if (keycode == 125)
		data->y2d_offset -= 5.0;
	else if (keycode == 123)
		data->x2d_offset += 5.0;
	else if (keycode == 124)
		data->x2d_offset -= 5.0;
	return (0);
}

int		key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		free_data(data);
		exit(1);
	}
	else if (keycode == 34)
		iso_mode(data);
	else if (keycode == 35)
		par_mode(data);
	par_instructions(data, keycode);
	gen_instructions(data, keycode);
	print_new_img(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->imgdata->img_ptr, 0, 0);
	return (0);
}
