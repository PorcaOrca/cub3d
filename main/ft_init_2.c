/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:45:30 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/23 10:41:15 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_server_init(t_param *param)
{
	param->texture->texture1 = NULL;
	param->texture->texture2 = NULL;
	param->texture->texture3 = NULL;
	param->texture->texture4 = NULL;
	param->texture->sprite = NULL;
	param->sprite_data->zbuffer = NULL;
	param->sprite_data->dist = NULL;
	param->sprite_data->sp_arr = NULL;
	param->sprite_data->order = NULL;
}

int			ft_vectors_init(t_param *param, t_temp *temp)
{
	if (!(param->vectors->dir = (t_vector *)malloc(sizeof(t_vector))))
		return (0);
	if (!(param->vectors->pos = (t_vector *)malloc(sizeof(t_vector))))
		return (0);
	if (!(param->vectors->plane = (t_vector *)malloc(sizeof(t_vector))))
		return (0);
	param->vectors->pos->x = temp->position[0];
	param->vectors->pos->y = temp->position[1];
	param->vectors->dir->x = temp->t_dirx;
	param->vectors->dir->y = temp->t_diry;
	param->vectors->plane->x = temp->t_planex;
	param->vectors->plane->y = temp->t_planey;
	return (1);
}

void		ft_sp_arr_init(t_param *param)
{
	int		i;
	int		j;
	int		s;

	i = 0;
	s = 0;
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
		{
			if (param->map[i][j] == '2')
			{
				param->sprite_data->sp_arr[s].s_pos_x = j + 0.5;
				param->sprite_data->sp_arr[s].s_pos_y = i + 0.5;
				param->sprite_data->sp_arr[s].s_txt = param->texture->sprite;
				param->map[i][j] = '0';
				s++;
			}
			j++;
		}
		i++;
	}
}

void		ft_param_init(t_param *param, t_temp *temp)
{
	param->map = temp->temp_map;
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
	param->settings->window_size_x = temp->width;
	param->settings->window_size_y = temp->height;
/*
	int		x;
	int		y;

	x = mlx_get_screen_size(param->mlx, x, y);
	if (param->settings->window_size_x > x)
		param->settings->window_size_x = x;
	if (param->settings->window_size_y > y)
		param->settings->window_size_y = y;
*/	
	param->settings->movement = 0.1;
	param->settings->rotation = 0.05;
	param->settings->floor_trgb = temp->floor_color;
	param->settings->ceiling_trgb = temp->ceiling_color;
	param->keys->mv_down = 0;
	param->keys->mv_up = 0;
	param->keys->mv_left = 0;
	param->keys->mv_right = 0;
	param->keys->rt_left = 0;
	param->keys->rt_right = 0;
}
