/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:46:34 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/13 01:15:17 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <mlx.h>
# define BUFF 2048
# define WIDTH 1920
# define HEIGHT 1080

/*
** struct containing all datas for a variable
*/

typedef struct	s_imgdata
{
	void	*img_ptr;
	char	*img_content;
	int		bits_in_pix;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}				t_imgdata;

typedef struct	s_point
{
	int x;
	int y;
	int color;
}				t_point;

typedef struct	s_seg
{
	t_point	pt0;
	t_point	pt1;
}				t_seg;

typedef struct	s_ptdata
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_ptdata;

/*
** t_ptstable contains all 3D points datas with coordinates and color
*/

typedef struct	s_ptstable
{
	int			x_max;
	int			y_max;
	t_ptdata	*table;
}				t_ptstable;

typedef struct	s_data
{
	int			mode;
	double		x;
	double		y;
	double		z;
	double		a;
	int			a_int;
	double		w;
	int			w_int;
	double		x2d;
	double		y2d;
	double		zoom;
	double		x3d_offset;
	double		y3d_offset;
	double		x2d_offset;
	double		y2d_offset;
	double		z_proportion;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_ptstable	tab;
	t_imgdata	*imgdata;
}				t_data;

int				print_new_img(t_data *data);
double			pirotation(int *var, int op);
int				printgrid(t_data *data);

/*
** ft_readfile
*/
char			*ft_readfile(const char *path);
typedef struct s_part	t_part;
struct			s_part
{
	size_t		len;
	char		str[BUFF];
	t_part		*next;
};

/*
** modes
*/
int				iso_mode(t_data *data);
int				par_mode(t_data *data);
int				par_instructions(t_data *data, int keycode);
int				gen_instructions(t_data *data, int keycode);
int				key_hook(int keycode, t_data *data);

/*
** segments and seg utils
*/
int				ft_segt_landing(t_imgdata *data, t_seg seg);
int				ft_segt_plane(t_imgdata *data, t_seg seg);
int				ft_segt_fall(t_imgdata *data, t_seg seg);
int				ft_segt_rocket(t_imgdata *data, t_seg seg);
int				ft_segment(t_imgdata *data, t_seg seg);

int				ft_isinwin(int x, int y);
int				ft_what_color(int x, int x_max, t_seg seg);

/*
** atois
*/
int				ft_isdigit(char c);
int				ft_ishexa(char c);
int				mini_atoi_hexa(char *str, int *h);
int				mini_atoi(char *str, int *h);

/*
** ft_parsing
*/
int				parser(t_data *data, char *str);

/*
** ft_image
*/
t_imgdata		*ft_create_img(void *mlx_ptr, int width, int height);
int				ft_color_pix(t_imgdata *data, int x, int y, int color);

/*
** free
*/
int				free_t_parts(t_part *init);
void			free_str(char *str);
int				free_data(t_data *data);

int				x_max(char *str);
int				y_max(char *str);
int				space_skip(char *str, int i);

#endif
