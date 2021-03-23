/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:05:28 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/23 09:29:55 by lodovico         ###   ########.fr       */
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
	ft_close_img(param->mlx, txt_1);
	ft_close_img(param->mlx, txt_2);
	ft_close_img(param->mlx, txt_3);
	ft_close_img(param->mlx, txt_4);
	ft_close_img(param->mlx, txt_spr);
	mlx_clear_window(param->mlx, param->win);
	mlx_destroy_window(param->mlx, param->win);
	ft_free_matrix(param->map);
	free(param->vectors->dir);
	free(param->vectors->plane);
	free(param->vectors->pos);
	free(param->vectors);
	free(param->settings);
	free(sp_data->zbuffer);
	free(sp_data->order);
	free(sp_data->sp_arr);
	free(sp_data->dist);
	free(wl_data);
	free(sp_data);
	free(param->common_data);
	free(param->keys);
	free(param);
	exit(0);
	return (0);
}
