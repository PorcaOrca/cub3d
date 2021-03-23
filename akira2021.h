/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   akira2021.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:32:58 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/23 09:18:48 by lodovico         ###   ########.fr       */
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

// macros definition

# define posX		param->vectors->pos->x
# define posY		param->vectors->pos->y
# define dirX		param->vectors->dir->x
# define dirY		param->vectors->dir->y
# define planeX		param->vectors->plane->x
# define planeY		param->vectors->plane->y
# define movspeed	param->settings->movement
# define rotspeed	param->settings->rotation
# define winX		param->settings->window_size_x
# define winY		param->settings->window_size_y
# define f_trgb		param->settings->floor_trgb
# define c_trgb		param->settings->ceiling_trgb
# define Wmap		param->map
# define txt_1		param->texture->texture1
# define txt_2		param->texture->texture2
# define txt_3		param->texture->texture3
# define txt_4		param->texture->texture4
# define txt_spr	param->texture->sprite
# define txt_sb		param->texture->skybox
# define txt_f_1	param->texture->floor_1
# define fl_data	param->floor_data
# define wl_data	param->wall_data
# define sp_data	param->sprite_data
# define trgb		param->common_data->color_trgb
# define i_x		param->common_data->iterator_x
# define i_y		param->common_data->iterator_y
# define txtX		param->common_data->texture_X
# define txtY		param->common_data->texture_Y

// param structs definition (everything goes there)

// settings struct
typedef struct	s_settings
{
	double		movement;
	double		rotation;
	int			window_size_x;
	int			window_size_y;
	int			floor_trgb;
	int			ceiling_trgb;
}				t_settings;

// img datas struct
typedef struct	s_img
{
	void		*ptr;
	char		*addr;
	int			bxp;
	int			sizel;
	int			endian;
}				t_img;

// textures struct imagine all the imagine

typedef	struct	s_txt
{
	t_img	*txt_data;
	int		texture_Width;
	int		texture_High;
}				t_txt;

typedef struct	s_texture
{
	t_txt	*texture1;
	t_txt	*texture2;
	t_txt	*texture3;
	t_txt	*texture4;
	t_txt	*sprite;
}				t_texture;

// model for vector struct
typedef	struct	s_vector
{
	double		x;
	double		y;
}				t_vector;

// raycasting data struct
typedef struct	s_rayc
{
	t_vector	*pos;
	t_vector	*dir;
	t_vector	*plane;
}				t_rayc;

// wall data struct
typedef struct		s_wl_data
{
	t_vector	raydir;
	t_vector	sidedist;
	t_vector	deltadist;
	t_txt		*txt;
	double		camerax;
	double		walldist;
	int 		stepx;
    int			stepy;
    int 		side;
	int			mapx;
	int			mapy;
	int			lineh;
	int			ystart;
	int			yend;
	double		txtpos;
	double		wallX;
	double		step;
	int			hit;
}					t_wl_data;

// common data struct
typedef struct		s_common
{
	int		iterator_x;
	int		iterator_y;
	int		color_trgb;
	int		texture_X;
	int		texture_Y;
}					t_common;

// sprite struct

typedef struct		s_spr
{
	double	s_pos_x;
	double	s_pos_y;
	t_txt	*s_txt;
}					t_spr;

// sprite data struct

typedef struct		s_sp_data
{
	t_spr	*sp_arr;
    int		i;
    double	*zbuffer;
    int		*order;
    double	*dist;
    double	spriteX;
    double	spriteY;
    double	invdet;
    double	transX;
    double	transY;
    int		spscreenX;
    int		spriteH;
    int		spriteW;
    int		spstartY;
    int		spendY;
    int		spstartX;
    int		spendX;
	int		stripe;
	int		d;
}					t_sp_data;

// key status struct

typedef struct		t_key_stat
{
	int		mv_up;
	int		mv_down;
	int		mv_left;
	int		mv_right;
	int		rt_left;
	int		rt_right;
}					t_key_stat;


// all the parameter are here btw....it' s not working
typedef struct	s_param
{
	void		*mlx;
	void		*win;
	t_rayc		*vectors;
	t_img		*img;
	t_settings	*settings;
	t_texture	*texture;
	t_common	*common_data;
	t_wl_data	*wall_data;
	t_sp_data	*sprite_data;
	t_key_stat	*keys;
	int			sprite_num;
	char		**map;
}				t_param;

// temp struct for the initial read

typedef struct		s_temp
{
	char	*texture1;
	char	*texture2;
	char	*texture3;
	char	*texture4;
	char	*txt_sprite;
	char	**temp_map;
	int		position[2];
	int		sprite_q;
	int		width;
	int		height;
	int		floor_color;
	int		ceiling_color;
	double	t_dirX;
	double	t_dirY;
	double	t_planeX;
	double	t_planeY;
	int		error;
}					t_temp;

// image management prototipes

int			ft_color(double shade, int r, int g, int b);
void		ft_img_fill(t_param *param);
t_img		*ft_img_init(t_param *param);
void		ft_img_pixel_put(t_img *img, int x, int y, int color);
void		ft_fill_line(t_param *param);
void		ft_fill_px(t_param *param);
void		ft_fill_column(t_param *param);
void		ft_calc_column(t_param *param);
void		ft_dda(t_param *param);
void		ft_step(t_param *param);
void		ft_deltadist(t_wl_data *data);
void		ft_img_wall(t_param *param);
void		ft_sprite_sort(int	*order, double *dist, int q);
void		ft_sprite(t_param *param);
void		ft_close_img(void * mlx_ptr, t_txt *txt);

// map and .cub file parsers prototipes

void		ft_temp_init(t_temp *temp);
void		ft_free_matrix(char **matrix);
int			ft_valid_cub(t_temp *temp);
void		ft_clean(t_temp *temp);
int			ft_resolution(t_temp *temp, char *str);
int			ft_back_color(char *str);
int			ft_background(char *str);
void		ft_clean(t_temp *temp);
void		ft_element_select(t_temp *temp, char *str);
void		ft_spawn(t_temp *temp, char position);
int			ft_map_check(char **matrix);
void		ft_map_fill(char **matrix, t_temp *temp, t_list *line, int map_size);
char		**ft_map(t_temp *temp, int fd, char *str);
int			ft_char_check(char **matrix, int i, int j);
int			ft_limit(char **matrix, int i);
void		ft_map_obj(char **matrix, int i, int j, t_temp *temp);
char		**ft_lst_to_matrix(t_temp *temp, t_list *line);



// texture management prototipes

t_txt		*ft_txt_init(t_param *param, char *path);
int			ft_get_txtcolor(t_img *img, int x, int y);


// event management prototipes

int			ft_close(t_param *param);
void		ft_close_img(void * mlx_ptr, t_txt *txt);
int			ft_new_frame(t_param *param);
void		ft_movement(t_param *param);
int			ft_key_release(int keycode, t_param *param);
int			ft_key_press(int keycode, t_param *param);
void		ft_forward(t_param *param, double coll);
void		ft_backward(t_param *param, double coll);
void		ft_strafe_right(t_param *param, double coll);
void		ft_strafe_left(t_param *param, double coll);
void		ft_movement(t_param *param);
void		ft_rotate_right(t_param *param);
void		ft_rotate_left(t_param *param);

// main prototipes

t_param		*ft_init(t_temp *temp);
int			ft_cub_init(t_temp *temp, char *mapfile);
void		ft_param_clean(t_param *param);
int			ft_param_alloc(t_param *param, t_temp *temp);
void		ft_server_clean(t_param *param);
int			ft_server_alloc(t_param *param, t_temp *temp);
void		ft_server_init(t_param *param);
int			ft_vectors_init(t_param *param, t_temp *temp);
void		ft_sp_arr_init(t_param *param);
void		ft_param_init(t_param *param, t_temp *temp);
void		ft_settings_init(t_param *param, t_temp *temp);


// utils prototipes
int			get_next_line(int fd, char **line);
void		ft_bmp(t_param *param);
void		ft_file_header(t_param *param, int fd, int pad);
void		ft_bmp_header(t_param *param, int fd);
void		ft_bmp_data(t_param *param, int fd);

// write a string cause i am lazy
void	debug();
void	debugstr(char *str);
// write nbr cause i hate printf
void	debugint(int nbr);
int		ft_madonna(t_param *param);


#endif
