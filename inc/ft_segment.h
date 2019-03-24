/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_segment.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:45:23 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/24 21:49:55 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SEGMENT_H
# define FT_SEGMENT_H

int			ft_segt_plane(t_imgdata *data, int x, int y, int i, int j);
int			ft_segt_fall(t_imgdata *data, int x, int y, int i, int j);
int			ft_segt_rocket(t_imgdata *data, int x, int y, int i, int j);
int			ft_segment(t_imgdata *data, t_point one, t_point two);

#endif