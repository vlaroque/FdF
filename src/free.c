/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:02:29 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/18 22:11:35 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

int		free_t_parts(t_part *init)
{
	t_part	*save;

	while (init)
	{
		save = init->next;
		free(init);
		init = save;
	}
	return (0);
}

void	free_str(char *str)
{
	if (str)
		free(str);
}

int		free_data(t_data *data)
{
	if (data->tab.table)
	{
		free(data->tab.table);
		data->tab.table = NULL;
	}
	if (data->imgdata)
	{
		mlx_destroy_image(data->mlx_ptr, data->imgdata);
		data->imgdata = NULL;
	}
	if (data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (-1);
}

int		return_message(char *str, int nbr)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
	return (nbr);
}
