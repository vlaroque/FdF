/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:36:13 by vlaroque          #+#    #+#             */
/*   Updated: 2019/04/05 16:25:58 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_parsing.h"

static int	howmanybefore(char *str, char what, char end)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while(str[i] && str[i] != end)
	{
		if (i == 0 && str[i] == what)
			res++;
		else if (i == 0)
			i = 0;
		else if (str[i] == what && str[i - 1] != what)
			res++;
		i++;
	}
	return (res);
}

t_ptstable	*parser(char *str)
{
	t_ptstable	*table;
	int i;

	i = 0;
	if(!(table = (t_ptstable *)malloc(sizeof(t_ptstable))))
		return (NULL);
	table->x_max = howmanybefore(str, ' ', '\n') + 1;
	table->y_max = howmanybefore(str, '\n', '\0') + 1;
}