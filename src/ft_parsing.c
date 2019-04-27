/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:36:13 by vlaroque          #+#    #+#             */
/*   Updated: 2019/04/27 19:00:30 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "ft_parsing.h"

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

static int x_max(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while(str[i] && str[i] != '\n')
	{
		if (i == 0 && str[i] && str[i] != ' ')
			res += 1;
		else if (str[i] != ' ' && str[i - 1] == ' ')
			res += 1;
		i++;
	}
	return (res);
}

static int y_max(char *str)
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

t_ptdata	*parsing_fill(char *str, t_ptdata *pts, int x_max, int y_max)
{
	int	x;
	int	y;
	int i;

	y = 0;
	i = 0;
	while(y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			while (str[i] == ' ')
				i++;
			if (ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+')
				pts[x + (y * x_max)].z = mini_atoi(str, &i);
			if (str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x')
			{
				i += 3;
				pts[x + (y * x_max)].color = mini_atoi_hexa(str, &i);
			}
			else
				pts[x + (y * x_max)].color = 0xFFFFFF;
			pts[x + (y * x_max)].x = x;
			pts[x + (y * x_max)].y = y;
			//printf("x = %d, y = %d z = %d  color = %#x\n", x, y,pts[x + (y * x_max)].z, pts[x + (y * x_max)].color);
			x++;
		}
		while (str[i] == ' ')
			i++;
		if (str[i] != '\n')
			return (NULL);
		i++;
		y++;
	}
	return (pts);
}

t_ptstable	*parser(char *str)
{
	t_ptstable	*grid;
	int i;

	i = 0;
	if(!(grid = (t_ptstable *)malloc(sizeof(t_ptstable))))
		return (NULL);
	grid->x_max = x_max(str);
	grid->y_max = y_max(str);
	if (!(grid->table = (t_ptdata *)malloc((sizeof(t_ptdata) * grid->x_max * grid->y_max))))
		return (NULL);
	grid->table = parsing_fill(str, grid->table, grid->x_max, grid->y_max);
	return (grid);
}







