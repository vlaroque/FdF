/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:49:01 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/11 18:59:32 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			x_max(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i] && str[i] != '\n')
	{
		if (i == 0 && str[i] && str[i] != ' ')
			res += 1;
		else if (str[i] != ' ' && str[i - 1] == ' ')
			res += 1;
		i++;
	}
	return (res);
}

int			y_max(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			res += 1;
		i++;
	}
	return (res);
}

int			space_skip(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}
