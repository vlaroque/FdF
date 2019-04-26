/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:14:01 by vlaroque          #+#    #+#             */
/*   Updated: 2019/04/18 18:36:30 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IMG_H
# define FT_IMG_H

t_imgdata	*ft_create_img(void *mlx_ptr, int width, int height);
int			ft_color_pix(t_imgdata *data, int x, int y, int color);

#endif
