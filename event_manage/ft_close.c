/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:05:28 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/25 11:31:53 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_close_img(void *mlx_ptr, t_txt *txt)
{
	mlx_destroy_image(mlx_ptr, txt->txt_data->ptr);
	free(txt->txt_data);
	free(txt);
}

int			ft_close(t_param *param)
{
	ft_close_img(param->mlx, param->texture->texture1);
	ft_close_img(param->mlx, param->texture->texture2);
	ft_close_img(param->mlx, param->texture->texture3);
	ft_close_img(param->mlx, param->texture->texture4);
	ft_close_img(param->mlx, param->texture->sprite);
	mlx_clear_window(param->mlx, param->win);
	mlx_destroy_window(param->mlx, param->win);
	ft_free_matrix(param->map);
	free(param->vectors->dir);
	free(param->vectors->plane);
	free(param->vectors->pos);
	free(param->vectors);
	free(param->settings);
	free(param->sprite_data->zbuffer);
	free(param->sprite_data->order);
	free(param->sprite_data->sp_arr);
	free(param->sprite_data->dist);
	free(param->wall_data);
	free(param->sprite_data);
	free(param->common_data);
	free(param->keys);
	free(param->texture);
	free(param);
	exit(0);
	return (0);
}
