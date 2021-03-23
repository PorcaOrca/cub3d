/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_wall_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:30:45 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/23 10:36:21 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void	ft_fill_px(t_param *param)
{
	param->wall_data->txtpos = (param->wall_data->ystart - param->settings->window_size_y / 2 + param->wall_data->lineh / 2)
						* param->wall_data->step;
	while (param->wall_data->ystart < param->wall_data->yend)
	{
		param->common_data->texture_y = (int)param->wall_data->txtpos;
		param->common_data->color_trgb = ft_get_txtcolor(param->wall_data->txt->txt_data, param->common_data->texture_x, param->common_data->texture_y);
		ft_img_pixel_put(param->img, param->common_data->iterator_x, param->wall_data->ystart, param->common_data->color_trgb);
		param->wall_data->txtpos += param->wall_data->step;
		param->wall_data->ystart++;
	}
}

void	ft_fill_column(t_param *param)
{
	if (param->wall_data->side == 0)
		param->wall_data->wallx = param->vectors->pos->y + (param->wall_data->walldist * param->wall_data->raydir.y);
	else
		param->wall_data->wallx = param->vectors->pos->x + (param->wall_data->walldist * param->wall_data->raydir.x);
	param->wall_data->wallx -= floor((param->wall_data->wallx));
	param->common_data->texture_x = (int)(param->wall_data->wallx * (double)param->wall_data->txt->texture_width);
	if (param->wall_data->side == 0 && param->wall_data->raydir.x > 0)
		param->common_data->texture_x = param->wall_data->txt->texture_width - param->common_data->texture_x - 1;
	if (param->wall_data->side == 1 && param->wall_data->raydir.y < 0)
		param->common_data->texture_x = param->wall_data->txt->texture_width - param->common_data->texture_x - 1;
	param->wall_data->step = (1.0 * param->wall_data->txt->texture_high) / param->wall_data->lineh;
	ft_fill_px(param);
}

void	ft_calc_column(t_param *param)
{
	if (param->wall_data->side == 0)
		param->wall_data->walldist = (param->wall_data->mapx - param->vectors->pos->x +
			((1 - param->wall_data->stepx) / 2)) / param->wall_data->raydir.x;
	else
		param->wall_data->walldist = (param->wall_data->mapy - param->vectors->pos->y +
			((1 - param->wall_data->stepy) / 2)) / param->wall_data->raydir.y;
	param->wall_data->lineh = (int)(param->settings->window_size_y / param->wall_data->walldist);
	param->wall_data->ystart = (-param->wall_data->lineh / 2) + (param->settings->window_size_y / 2);
	if (param->wall_data->ystart < 0)
		param->wall_data->ystart = 0;
	param->wall_data->yend = (param->wall_data->lineh / 2) + (param->settings->window_size_y / 2);
	if (param->wall_data->yend >= param->settings->window_size_y)
		param->wall_data->yend = param->settings->window_size_y - 1;
}
