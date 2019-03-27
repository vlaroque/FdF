/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:46:34 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/27 16:30:31 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef		struct s_point
{
	int x;
	int y;
}			t_point;

typedef		struct s_seg
{
	t_point	pt0;
	t_point	pt1;
	int		clr0;
	int		clr1;
}			t_seg;

#endif