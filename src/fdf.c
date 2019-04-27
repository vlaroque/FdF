/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:20:45 by vlaroque          #+#    #+#             */
/*   Updated: 2019/04/27 20:48:34 by vlaroque         ###   ########.fr       */
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
	t_imgdata	*data;
	char		*path;
	char		*str;
	t_ptstable	*table;
	(void)ac;

	path = av[1];
	str = ft_readfile(path);
	if(!(table = parser(str)))
		return (0);
	int i = -1;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Une fenetre");
	data = ft_create_img(mlx_ptr, WIDTH, HEIGHT);
	printgrid(data, table);
	mlx_put_image_to_window(mlx_ptr, win_ptr, data->img_ptr, 0, 0);

	mlx_loop(mlx_ptr);
	return (0);
}
