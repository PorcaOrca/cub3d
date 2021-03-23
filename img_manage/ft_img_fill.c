/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:19:03 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/23 10:25:44 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void	ft_img_fill(t_param *param)
{
	param->common_data->iterator_x = 0;
	while (param->common_data->iterator_x < param->settings->window_size_x)
	{
		param->common_data->color_trgb = param->settings->ceiling_trgb;
		param->common_data->iterator_y = 0;
		while (param->common_data->iterator_y < param->settings->window_size_y)
		{
			if (param->common_data->iterator_y > (param->settings->window_size_y / 2))
				param->common_data->color_trgb = param->settings->floor_trgb;
			ft_img_pixel_put(param->img, param->common_data->iterator_x, param->common_data->iterator_y, param->common_data->color_trgb);
			param->common_data->iterator_y++;
		}
		param->common_data->iterator_x++;
	}
	ft_img_wall(param);
	ft_sprite(param);
}
