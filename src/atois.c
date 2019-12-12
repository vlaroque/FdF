/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atois.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:17:27 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/11 18:17:04 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

int			ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_ishexa(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else
		return (-1);
}

int			mini_atoi_hexa(char *str, int *h)
{
	int nbr;
	int sign;

	sign = 1;
	nbr = 0;
	if (str[*h] == '-' || str[*h] == '+')
	{
		if (str[*h] == '-')
			sign = -1;
		(*h)++;
	}
	while (ft_ishexa(str[*h]) >= 0)
	{
		nbr = (nbr * 16) + ft_ishexa(str[*h]);
		(*h)++;
	}
	return (nbr * sign);
}

int			mini_atoi(char *str, int *h)
{
	int nbr;
	int sign;

	sign = 1;
	nbr = 0;
	if (str[*h] == '-' || str[*h] == '+')
	{
		if (str[*h] == '-')
			sign = -1;
		(*h)++;
	}
	while (ft_isdigit(str[*h]))
	{
		nbr = (nbr * 10) + (str[*h] - '0');
		(*h)++;
	}
	return (nbr * sign);
}
