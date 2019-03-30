/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:36:13 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/30 18:59:17 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_parsing.h"

t_ptstable	*parser(char *str)
{
	t_ptstable	*table;
	int i;

	i = 0;
	if(!(table = (t_ptstable *)malloc(sizeof(t_ptstable))))
		return (NULL);
	table->x_max = 1;
	while(str[i] != '\n')
	{
		if (str[i] == ' ')
			table->x_max++;
		i++;
	}
	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			table->y_max++;
		i++;
	}
}