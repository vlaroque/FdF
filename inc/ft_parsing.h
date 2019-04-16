/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:56:17 by vlaroque          #+#    #+#             */
/*   Updated: 2019/04/16 17:03:19 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PARSING_H
# define FT_PARSING_H

typedef struct	s_ptdata
{
	int			z;
	int			color;
}				t_ptdata;

typedef struct s_ptstable
{
	int			x_max;
	int			y_max;
	t_ptdata	*table;
}				t_ptstable;

t_ptstable	*parser(char *str);

#endif
