/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:20:45 by vlaroque          #+#    #+#             */
/*   Updated: 2019/04/16 17:59:14 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "fdf.h"
#include "ft_image.h"
#include "ft_segment.h"
#include "ft_readfile.h"
#include "ft_parsing.h"

int		main(int ac, char **av)
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_imgdata	*data;
	char		*path;
	char		*str;
	t_ptstable	*table;

	t_seg	seg = {{400 ,400, 0x0000ff}, {20, 350, 0xff0000}};

	path = av[1];
	str = ft_readfile(path);
	table = parser(str);
	int i = -1;
	while (++i < (table->x_max * table->y_max + 1))
		printf("i = %d | z = %d | color = %d\n", i table->table[i].z, table->table[i].color);

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Une fenetre");
	data = ft_create_img(mlx_ptr, 500, 500);
	ft_segment(data, seg);
	ft_color_pix(data, 200, 200, 0xffff00);
	mlx_put_image_to_window(mlx_ptr, win_ptr, data->img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
