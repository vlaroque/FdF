/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:02:29 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/12 14:14:36 by vlaroque         ###   ########.fr       */
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

	return (-1);
}
