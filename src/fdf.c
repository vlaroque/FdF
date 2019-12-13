/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:20:45 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/13 01:30:57 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

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
	if (*var == 0)
		return (0);
	return (((double)*var) / 40.0 * M_PI);
}

int		first_init(t_data *data)
{
	par_mode(data);
	data->x3d_offset = (double)data->tab.x_max / 2.0 - 0.5;
	data->y3d_offset = (double)data->tab.y_max / 2.0 - 0.5;
	data->x2d_offset = ((double)WIDTH) / 2.0;
	data->y2d_offset = ((double)HEIGHT) / 2.0;
	printgrid(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->imgdata->img_ptr, 0, 0);
	return (0);
}

int		main(int ac, char **av)
{
	char			*path;
	char			*str;
	static t_data	data;

	(void)ac;
	path = av[1];
	if (!(str = ft_readfile(path)))
		return (-1);
	if (!(parser(&data, str)))
	{
		free_str(str);
		return (-1);
	}
	free_str(str);
	if (!(data.mlx_ptr = mlx_init()))
		return (free_data(&data));
	if (!(data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Fdf")))
		return (free_data(&data));
	if (!(data.imgdata = ft_create_img(data.mlx_ptr, WIDTH, HEIGHT)))
		return (free_data(&data));
	first_init(&data);
	mlx_hook(data.win_ptr, 2, 0, &key_hook, (void *)&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
