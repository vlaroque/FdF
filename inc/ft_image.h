/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:14:01 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/24 20:54:13 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IMG_H
# define FT_IMG_H

typedef		struct s_imgdata
{
	void	*img_ptr;
	char	*img_data;
	int		bits_in_pix;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}			t_imgdata;

t_imgdata	*ft_create_img(void *mlx_ptr, int width, int height);
int			ft_color_pix(t_imgdata *data, int x, int y, int color);



#endif