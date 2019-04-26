/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:46:34 by vlaroque          #+#    #+#             */
/*   Updated: 2019/04/26 11:52:44 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
 * ft_image.h
 * struct de l'image a afficher
 */

typedef		struct s_imgdata
{
	void	*img_ptr;
	char	*img_content;
	int		bits_in_pix;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}			t_imgdata;

/*
 * t_point contient informations sur un point a placer en 2D avec le X, Y et
 * la couleur.
 * t_seg necessaire pour la transmission d'un segment a partir de deux pts
 */

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

/*
 * t_ptstable contient tous les points avec leurs dimentions en 3D
 * t_ptdata contient les informations sur le z et la couleur d'un pt
 */

typedef struct	s_ptdata
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_ptdata;

typedef struct s_ptstable
{
	int			x_max;
	int			y_max;
	t_ptdata	*table;
}				t_ptstable;

/* window informations */
# define WIDTH 500
# define HEIGHT 400

#endif
