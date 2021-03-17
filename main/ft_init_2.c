/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:45:30 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/17 09:48:40 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

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

int			ft_vectors_init(t_param *param, t_temp *temp)
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

void		ft_settings_init(t_param *param, t_temp *temp)
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
