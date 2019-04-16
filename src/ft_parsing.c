/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:36:13 by vlaroque          #+#    #+#             */
/*   Updated: 2019/04/16 17:54:35 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_parsing.h"

int			ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_ishexa(char c)
{
	if (c >= '0' && c <= '0')
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
//	printf("     >>> nbr = %d | i = %d   <<<\n", nbr * sign, *h);
	return (nbr * sign);
}

static int	howmanybefore(char *str, char what, char end)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while(str[i] && str[i] != end)
	{
		if (i == 0 && str[i] == what)
		{
			res++;
			while (str[i] == what)
				i++;
		}
		else if (i == 0)
			i = 0;
		else if (str[i] == what && str[i - 1] != what)
			res++;
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
//			printf("i  = %d\n", i);
			x++;
		}
	while (str[i] == ' ')
		i++;
	if (str[i] != '\n')
		return (NULL);
//	printf("next i  = %d   char = |%c| \n", i, str[i]);
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
//	printf("str= \n[%s]\n", str);
	if(!(grid = (t_ptstable *)malloc(sizeof(t_ptstable))))
		return (NULL);
	grid->x_max = howmanybefore(str, ' ', '\n');
	grid->y_max = howmanybefore(str, '\n', '\0');
	if (!(grid->table = (t_ptdata *)malloc(sizeof(t_ptdata) * grid->x_max * grid->y_max)))
		return (0);
	grid->table = parsing_fill(str, grid->table, grid->x_max, grid->y_max);
//	printf("x_max = %d, y_max = %d", grid->x_max, grid->y_max);
	return (grid);
}







