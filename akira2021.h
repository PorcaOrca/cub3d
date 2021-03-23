/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   akira2021.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:32:58 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/23 12:04:04 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AKIRA2021_H
# define AKIRA2021_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <string.h>
# include "libft/libft.h"

typedef struct	s_settings
{
	double		movement;
	double		rotation;
	int			window_size_x;
	int			window_size_y;
	int			floor_trgb;
	int			ceiling_trgb;
}				t_settings;

typedef struct	s_img
{
	void		*ptr;
	char		*addr;
	int			bxp;
	int			sizel;
	int			endian;
}				t_img;

typedef	struct	s_txt
{
	t_img	*txt_data;
	int		texture_width;
	int		texture_high;
}				t_txt;

typedef struct	s_texture
{
	t_txt	*texture1;
	t_txt	*texture2;
	t_txt	*texture3;
	t_txt	*texture4;
	t_txt	*sprite;
}				t_texture;

typedef	struct	s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct	s_rayc
{
	t_vector	*pos;
	t_vector	*dir;
	t_vector	*plane;
}				t_rayc;

typedef struct	s_wall_data
{
	t_vector	raydir;
	t_vector	sidedist;
	t_vector	deltadist;
	t_txt		*txt;
	double		camerax;
	double		walldist;
	int			stepx;
	int			stepy;
	int			side;
	int			mapx;
	int			mapy;
	int			lineh;
	int			ystart;
	int			yend;
	double		txtpos;
	double		wallx;
	double		step;
	int			hit;
}				t_wall_data;

typedef struct	s_common
{
	int		iterator_x;
	int		iterator_y;
	int		color_trgb;
	int		texture_x;
	int		texture_y;
}				t_common;

typedef struct	s_spr
{
	double	s_pos_x;
	double	s_pos_y;
	t_txt	*s_txt;
}				t_spr;

typedef struct	s_sp_data
{
	t_spr	*sp_arr;
	int		i;
	double	*zbuffer;
	int		*order;
	double	*dist;
	double	spritex;
	double	spritey;
	double	invdet;
	double	transx;
	double	transy;
	int		spscreenx;
	int		spriteh;
	int		spritew;
	int		spstarty;
	int		spendy;
	int		spstartx;
	int		spendx;
	int		stripe;
	int		d;
}				t_sp_data;

typedef struct	s_key_stat
{
	int		mv_up;
	int		mv_down;
	int		mv_left;
	int		mv_right;
	int		rt_left;
	int		rt_right;
}				t_key_stat;

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	t_rayc		*vectors;
	t_img		*img;
	t_settings	*settings;
	t_texture	*texture;
	t_common	*common_data;
	t_wall_data	*wall_data;
	t_sp_data	*sprite_data;
	t_key_stat	*keys;
	int			sprite_num;
	char		**map;
}				t_param;

typedef struct	s_temp
{
	char	*texture1;
	char	*texture2;
	char	*texture3;
	char	*texture4;
	char	*sprite;
	char	**temp_map;
	int		position[2];
	int		sprite_q;
	int		width;
	int		height;
	int		floor_color;
	int		ceiling_color;
	double	t_dirx;
	double	t_diry;
	double	t_planex;
	double	t_planey;
	int		error;
}				t_temp;

int				ft_color(double shade, int r, int g, int b);
void			ft_img_fill(t_param *param);
t_img			*ft_img_init(t_param *param);
void			ft_img_pixel_put(t_img *img, int x, int y, int color);
void			ft_fill_line(t_param *param);
void			ft_fill_px(t_param *param);
void			ft_fill_column(t_param *param);
void			ft_calc_column(t_param *param);
void			ft_dda(t_param *param);
void			ft_step(t_param *param);
void			ft_deltadist(t_wall_data *data);
void			ft_img_wall(t_param *param);
void			ft_sprite_sort(int *order, double *dist, int q);
void			ft_sprite(t_param *param);
void			ft_close_img(void *mlx_ptr, t_txt *txt);

void			ft_temp_init(t_temp *temp);
void			ft_free_matrix(char **matrix);
int				ft_valid_cub(t_temp *temp);
void			ft_clean(t_temp *temp);
int				ft_resolution(t_temp *temp, char *str);
int				ft_back_color(char *str);
int				ft_background(char *str);
void			ft_clean(t_temp *temp);
void			ft_element_select(t_temp *temp, char *str);
void			ft_spawn(t_temp *temp, char position);
int				ft_map_check(char **matrix);
void			ft_map_fill(char **matrix, t_temp *temp,
						t_list *line, int map_size);
char			**ft_map(t_temp *temp, int fd, char *str);
int				ft_char_check(char **matrix, int i, int j);
int				ft_limit(char **matrix, int i);
void			ft_map_obj(char **matrix, int i, int j, t_temp *temp);
char			**ft_lst_to_matrix(t_temp *temp, t_list *line);

t_txt			*ft_txt_init(t_param *param, char *path);
int				ft_get_txtcolor(t_img *img, int x, int y);

int				ft_close(t_param *param);
void			ft_close_img(void *mlx_ptr, t_txt *txt);
int				ft_new_frame(t_param *param);
void			ft_movement(t_param *param);
int				ft_key_release(int keycode, t_param *param);
int				ft_key_press(int keycode, t_param *param);
void			ft_forward(t_param *param, double coll);
void			ft_forward_x(t_param *param, double coll);
void			ft_forward_y(t_param *param, double coll);
void			ft_backward(t_param *param, double coll);
void			ft_backward_x(t_param *param, double coll);
void			ft_backward_y(t_param *param, double coll);
void			ft_strafe_right(t_param *param, double coll);
void			ft_strafe_right_x(t_param *param, double coll);
void			ft_strafe_right_y(t_param *param, double coll);
void			ft_strafe_left(t_param *param, double coll);
void			ft_strafe_left_x(t_param *param, double coll);
void			ft_strafe_left_y(t_param *param, double coll);
void			ft_movement(t_param *param);
void			ft_rotate_right(t_param *param);
void			ft_rotate_left(t_param *param);

t_param			*ft_init(t_temp *temp);
int				ft_cub_init(t_temp *temp, char *mapfile);
void			ft_param_clean(t_param *param);
int				ft_param_alloc(t_param *param, t_temp *temp);
void			ft_server_clean(t_param *param);
int				ft_server_alloc(t_param *param, t_temp *temp);
void			ft_server_init(t_param *param);
int				ft_vectors_init(t_param *param, t_temp *temp);
void			ft_sp_arr_init(t_param *param);
void			ft_param_init(t_param *param, t_temp *temp);
void			ft_settings_init(t_param *param, t_temp *temp);

int				get_next_line(int fd, char **line);
void			ft_bmp(t_param *param);
void			ft_file_header(t_param *param, int fd, int pad);
void			ft_bmp_header(t_param *param, int fd);
void			ft_bmp_data(t_param *param, int fd);

#endif
