/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:46:34 by vlaroque          #+#    #+#             */
/*   Updated: 2019/04/05 11:52:05 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef		struct s_point
{
	int x;
	int y;
	int color;
}			t_point;

typedef		struct s_seg
{
	t_point	pt0;
	t_point	pt1;
}			t_seg;

#endif