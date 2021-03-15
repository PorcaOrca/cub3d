/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:15:35 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/15 11:24:16 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_param_clean(t_param *param)
{
	if (param->vectors)
	{
		if (param->vectors->dir)
			free(param->vectors->dir);
		if (param->vectors->pos)
			free(param->vectors->pos);
		if (param->vectors->plane)
			free(param->vectors->plane);
		free(param->vectors);
	}
	if (param->settings)
		free(param->settings);
	if (wl_data)
		free(wl_data);
	if (param->common_data)
		free(param->common_data);
	if (sp_data)
		free(sp_data);
	if (param->texture)
		free(param->texture);
}

int		ft_vectors_init(t_param *param, t_temp *temp)
{
	if (!(param->vectors->dir = (t_vector *)malloc(sizeof(t_vector))))
		return (0);
	if (!(param->vectors->pos = (t_vector *)malloc(sizeof(t_vector))))
		return (0);
	if (!(param->vectors->plane = (t_vector *)malloc(sizeof(t_vector))))
		return (0);
	posX = temp->position[0];
	posY = temp->position[1];
	dirX = temp->t_dirX;
	dirY = temp->t_dirY;
	planeX = temp->t_planeX;
	planeY = temp->t_planeY;
	return (1);
}

void	ft_settings_init(t_param *param, t_temp *temp)
{
	winX = temp->width;
	winY = temp->height;
/*
	int		x;
	int		y;

	x = mlx_get_screen_size(param->mlx, x, y);
	if (winX > x)
		winX = x;
	if (winY > y)
		winY = y;
*/	
	movspeed = 0.1;
	rotspeed = 0.05;
	f_trgb = temp->floor_color;
	c_trgb = temp->ceiling_color;
	param->keys->mv_down = 0;
	param->keys->mv_up = 0;
	param->keys->mv_left = 0;
	param->keys->mv_right = 0;
	param->keys->rt_left = 0;
	param->keys->rt_right = 0;
}

int		ft_param_alloc(t_param *param, t_temp *temp)
{
	if (!(param->vectors = (t_rayc *)malloc(sizeof(t_rayc))))
		return(0);
	param->vectors->dir = NULL;
	param->vectors->pos = NULL;
	param->vectors->plane = NULL;
	if (!ft_vectors_init(param, temp))
		return (0);
	if (!(param->settings = (t_settings *)malloc(sizeof(t_settings))))
		return (0);
	if (!(param->keys = (t_key_stat *)malloc(sizeof(t_key_stat))))
		return (0);
	ft_settings_init(param, temp);
	if (!(wl_data = (t_wl_data *)malloc(sizeof(t_wl_data))))
		return (0);
	if (!(param->common_data = (t_common *)malloc(sizeof(t_common))))
		return (0);
	if (!(sp_data = (t_sp_data *)malloc(sizeof(t_sp_data))))
		return (0);
	if (!(param->texture = (t_texture *)malloc(sizeof(t_texture))))
		return (0);
	return (1);
}

void	ft_server_clean(t_param *param)
{
	if(txt_1)
		ft_close_img(param->mlx, txt_1);
	if(txt_2)
		ft_close_img(param->mlx, txt_2);
	if(txt_3)
		ft_close_img(param->mlx, txt_3);
	if(txt_4)
		ft_close_img(param->mlx, txt_4);
	if(sp_data->zbuffer)
		free(sp_data->zbuffer);
	if(sp_data->dist)
		free(sp_data->dist);
	if(sp_data->order)
		free(sp_data->order);
	if(sp_data->sp_arr)
		free(sp_data->sp_arr);
	if(txt_spr)
		ft_close_img(param->mlx, txt_spr);
	if(param->win)
		mlx_destroy_window(param->mlx, param->win);
}

int		ft_server_alloc(t_param *param, t_temp *temp)
{
	if (!(param->mlx = mlx_init()))
		return (0);
	if (!(param->win = mlx_new_window(param->mlx, winX, winY, "akira2021")))
		return (0);
	if (!(txt_1 = ft_txt_init(param, temp->texture1)))
		return (0);
	if (!(txt_2 = ft_txt_init(param, temp->texture2)))
		return (0);
	if (!(txt_3 = ft_txt_init(param, temp->texture3)))
		return (0);
	if (!(txt_4 = ft_txt_init(param, temp->texture4)))
		return (0);
	if (!(sp_data->zbuffer = (double *)malloc(sizeof(double) * winX)))
		return (0);
	if (!(sp_data->dist = (double *)malloc(sizeof(double) * temp->sprite_q)))
		return (0);
	if (!(sp_data->order = (int *)malloc(sizeof(int) * temp->sprite_q)))
		return (0);
	if (!(sp_data->sp_arr = (t_spr *)malloc(sizeof(t_spr) * temp->sprite_q)))
		return (0);
	if (!(txt_spr = ft_txt_init(param, temp->txt_sprite)))
		return (0);
	return (1);
}

void		ft_server_init(t_param *param)
{
	txt_1 = NULL;
	txt_2 = NULL;
	txt_3 = NULL;
	txt_4 = NULL;
	txt_spr = NULL;
	sp_data->zbuffer = NULL;
	sp_data->dist = NULL;
	sp_data->sp_arr = NULL;
	sp_data->order = NULL;
}

void		ft_sp_arr_init(t_param *param)
{
	int		i;
	int		j;
	int		s;

	i = 0;
	s = 0;
	while (Wmap[i])
	{
		j = 0;
		while (Wmap[i][j])
		{
			if (Wmap[i][j] == '2')
			{
				sp_data->sp_arr[s].s_pos_x = j + 0.5;
				sp_data->sp_arr[s].s_pos_y = i + 0.5;
				sp_data->sp_arr[s].s_txt = txt_spr;
				Wmap[i][j] = '0';
				s++;
			}
			j++;
		}
		i++;
	}
}

void		ft_param_init(t_param *param, t_temp *temp)
{
	Wmap = temp->temp_map;
	param->settings = NULL;
	param->vectors = NULL;
	param->keys = NULL;
	param->common_data = NULL;
	param->wall_data = NULL;
	param->sprite_data = NULL;
	param->texture = NULL;
	param->sprite_num = temp->sprite_q;
}

t_param		*ft_init(t_temp *temp)
{
	t_param	*param;

	if (!(param = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	ft_param_init(param, temp);
	if (!(ft_param_alloc(param, temp)))
	{
		ft_param_clean(param);
		return (NULL);
	}
	ft_server_init(param);
	if (!(ft_server_alloc(param, temp)))
	{
		ft_server_clean(param);
		ft_param_clean(param);
		return (NULL);
	}
	ft_sp_arr_init(param);
	free(temp->texture1);
	free(temp->texture2);
	free(temp->texture3);
	free(temp->texture4);
	return (param);
}