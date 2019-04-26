/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:20:45 by vlaroque          #+#    #+#             */
/*   Updated: 2019/04/19 07:16:37 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "fdf.h"
#include "ft_image.h"
#include "ft_segment.h"
#include "ft_readfile.h"
#include "ft_parsing.h"

int		printgrid(t_imgdata *img, t_ptstable *tab);

int		main(int ac, char **av)
{
	void		*mlx_ptr;
	void		*win_ptr;
	//void		*img_ptr;
	t_imgdata	*data;
	char		*path;
	char		*str;
	t_ptstable	*table;
	(void)ac;
	t_seg	seg = {{0 ,0, 0x0000ff}, {0, 5, 0xff0000}};

	path = av[1];
	str = ft_readfile(path);
	table = parser(str);
	int i = -1;
	while (++i < (table->x_max * table->y_max))
		printf("z = %d | c = %#x\n", table->table[i].z, table->table[i].color);

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Une fenetre");
	data = ft_create_img(mlx_ptr, WIDTH, HEIGHT);
//	ft_segment(data, seg);
	ft_color_pix(data, 200, 200, 0xffff00);
	printgrid(data, table);
	mlx_put_image_to_window(mlx_ptr, win_ptr, data->img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}

/*

#include "fdf.h"
#include "ft_segment.h"

t_point		transpoint(t_ptdata *pt3d)
{
	t_point pt2d;

	pt2d.color = pt3d->color;
	pt2d.x = pt3d->x * 10;
	pt2d.y = pt3d->y * 10 + pt3d->z * 5;
	return (pt2d);
}

void		seg(t_imgdata *data, t_ptdata one, t_ptdata two)
{
	t_seg seg;

	seg.pt0 = transpoint(&one);
	seg.pt1 = transpoint(&two);
	ft_segment(data, seg);
}

int		printgrid(t_imgdata *img, t_ptstable *tab)
{
	int i;

	i = 0;
	while (i < tab->x_max * tab->y_max)
	{
		if (i % tab->x_max != tab->x_max - 1)
			seg(img, tab->table[i], tab->table[i + 1]);
		if (i / tab->x_max != tab->y_max - 1)
			seg(img, tab->table[i], tab->table[i + tab->x_max]);
		i++;
	}
	return (1);
}
*/
