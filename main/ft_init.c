/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:15:35 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/25 10:32:21 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

int			ft_param_alloc(t_param *param, t_temp *temp)
{
	if (!(param->vectors = (t_rayc *)malloc(sizeof(t_rayc))))
		return (0);
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
	if (!(param->wall_data = (t_wall_data *)malloc(sizeof(t_wall_data))))
		return (0);
	if (!(param->common_data = (t_common *)malloc(sizeof(t_common))))
		return (0);
	if (!(param->sprite_data = (t_sp_data *)malloc(sizeof(t_sp_data))))
		return (0);
	if (!(param->texture = (t_texture *)malloc(sizeof(t_texture))))
		return (0);
	return (1);
}

void		ft_server_clean(t_param *param)
{
	if (param->texture->texture1)
		ft_close_img(param->mlx, param->texture->texture1);
	if (param->texture->texture2)
		ft_close_img(param->mlx, param->texture->texture2);
	if (param->texture->texture3)
		ft_close_img(param->mlx, param->texture->texture3);
	if (param->texture->texture4)
		ft_close_img(param->mlx, param->texture->texture4);
	if (param->sprite_data->zbuffer)
		free(param->sprite_data->zbuffer);
	if (param->sprite_data->dist)
		free(param->sprite_data->dist);
	if (param->sprite_data->order)
		free(param->sprite_data->order);
	if (param->sprite_data->sp_arr)
		free(param->sprite_data->sp_arr);
	if (param->texture->sprite)
		ft_close_img(param->mlx, param->texture->sprite);
	if (param->win)
		mlx_destroy_window(param->mlx, param->win);
}

int			ft_sprite_data_alloc(t_param *param, t_temp *temp)
{
	if (!(param->sprite_data->zbuffer =
			(double *)malloc(sizeof(double) * param->settings->window_size_x)))
		return (0);
	if (!(param->sprite_data->dist =
			(double *)malloc(sizeof(double) * temp->sprite_q)))
		return (0);
	if (!(param->sprite_data->order =
			(int *)malloc(sizeof(int) * temp->sprite_q)))
		return (0);
	if (!(param->sprite_data->sp_arr =
			(t_spr *)malloc(sizeof(t_spr) * temp->sprite_q)))
		return (0);
	if (!(param->texture->sprite = ft_txt_init(param, temp->sprite)))
		return (0);
	return (1);
}

int			ft_server_alloc(t_param *param, t_temp *temp)
{
	if (!(param->mlx = mlx_init()))
		return (0);
	if (!(param->win = mlx_new_window(param->mlx,
						param->settings->window_size_x,
						param->settings->window_size_y, "akira2021")))
		return (0);
	if (!(param->texture->texture1 = ft_txt_init(param, temp->texture1)))
		return (0);
	if (!(param->texture->texture2 = ft_txt_init(param, temp->texture2)))
		return (0);
	if (!(param->texture->texture3 = ft_txt_init(param, temp->texture3)))
		return (0);
	if (!(param->texture->texture4 = ft_txt_init(param, temp->texture4)))
		return (0);
	if (!ft_sprite_data_alloc(param, temp))
		return (0);
	return (1);
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
	free(temp->sprite);
	return (param);
}
