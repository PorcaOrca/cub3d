/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:11:54 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/25 10:07:38 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_spr_pxl(t_param *param, int i)
{
	param->sprite_data->d = (param->common_data->iterator_y * 256) -
	(param->settings->window_size_y * 128) +
	(param->sprite_data->spriteh * 128);
	param->common_data->texture_y = ((param->sprite_data->d *
	param->sprite_data->sp_arr
	[param->sprite_data->order[i]].s_txt->texture_high)
	/ param->sprite_data->spriteh) / 256;
	if (param->common_data->texture_y < 0)
		param->common_data->texture_y = -param->common_data->texture_y;
	if (param->common_data->texture_x < 0)
		param->common_data->texture_x = -param->common_data->texture_x;
	param->common_data->color_trgb =
	ft_get_txtcolor(param->sprite_data->sp_arr
		[param->sprite_data->order[i]].s_txt->txt_data,
		param->common_data->texture_x, param->common_data->texture_y);
	if (param->common_data->color_trgb != 0x00000000)
		ft_img_pixel_put(param->img, param->sprite_data->stripe,
		param->common_data->iterator_y, param->common_data->color_trgb);
}

void		ft_spr_to_frame(t_param *param, int i)
{
	param->sprite_data->stripe = param->sprite_data->spstartx;
	while (param->sprite_data->stripe < param->sprite_data->spendx)
	{
		param->common_data->texture_x = (int)(256 *
		(param->sprite_data->stripe -
		(-param->sprite_data->spritew / 2 + param->sprite_data->spscreenx))
		* param->sprite_data->sp_arr
		[param->sprite_data->order[i]].s_txt->texture_width
		/ param->sprite_data->spritew) / 256;
		if (param->sprite_data->transy > 0 &&
			param->sprite_data->stripe > 0 &&
			param->sprite_data->stripe < param->settings->window_size_x &&
			param->sprite_data->transy <
			param->sprite_data->zbuffer[param->sprite_data->stripe])
		{
			param->common_data->iterator_y = param->sprite_data->spstarty;
			while (param->common_data->iterator_y <
					param->sprite_data->spendy)
			{
				ft_spr_pxl(param, i);
				param->common_data->iterator_y++;
			}
		}
		param->sprite_data->stripe++;
	}
}

void		ft_spr_dim(t_param *param)
{
	param->sprite_data->spriteh = (int)(param->settings->window_size_y /
		param->sprite_data->transy);
	if (param->sprite_data->spriteh < 0)
		param->sprite_data->spriteh = -param->sprite_data->spriteh;
	param->sprite_data->spstarty = -param->sprite_data->spriteh /
		2 + param->settings->window_size_y / 2;
	if (param->sprite_data->spstarty < 0)
		param->sprite_data->spstarty = 0;
	param->sprite_data->spendy = param->sprite_data->spriteh /
		2 + param->settings->window_size_y / 2;
	if (param->sprite_data->spendy >= param->settings->window_size_y)
		param->sprite_data->spendy = param->settings->window_size_y - 1;
	param->sprite_data->spritew = (int)(param->settings->window_size_y /
		param->sprite_data->transy);
	if (param->sprite_data->spritew < 0)
		param->sprite_data->spritew = -param->sprite_data->spritew;
	param->sprite_data->spstartx = -param->sprite_data->spritew /
		2 + param->sprite_data->spscreenx;
	if (param->sprite_data->spstartx < 0)
		param->sprite_data->spstartx = 0;
	param->sprite_data->spendx = param->sprite_data->spritew /
		2 + param->sprite_data->spscreenx;
	if (param->sprite_data->spendx >= param->settings->window_size_x)
		param->sprite_data->spendx = param->settings->window_size_x - 1;
}

void		ft_sprite_order(t_param *param)
{
	int		i;

	i = 0;
	while (i < param->sprite_num)
	{
		param->sprite_data->order[i] = i;
		param->sprite_data->dist[i] =
		((param->vectors->pos->x - param->sprite_data->sp_arr[i].s_pos_x)
		* (param->vectors->pos->x - param->sprite_data->sp_arr[i].s_pos_x)
		+ (param->vectors->pos->y - param->sprite_data->sp_arr[i].s_pos_y)
		* (param->vectors->pos->y - param->sprite_data->sp_arr[i].s_pos_y));
		i++;
	}
	ft_sprite_sort(param->sprite_data->order,
		param->sprite_data->dist, param->sprite_num);
}

void		ft_sprite(t_param *param)
{
	param->i = 0;
	ft_sprite_order(param);
	while (param->i < param->sprite_num)
	{
		param->sprite_data->spritex = param->sprite_data->sp_arr
		[param->sprite_data->order[param->i]].s_pos_x - param->vectors->pos->x;
		param->sprite_data->spritey = param->sprite_data->sp_arr
		[param->sprite_data->order[param->i]].s_pos_y - param->vectors->pos->y;
		param->sprite_data->invdet =
		1 / ((param->vectors->plane->x * param->vectors->dir->y) -
		(param->vectors->dir->x * param->vectors->plane->y));
		param->sprite_data->transx = param->sprite_data->invdet
		* ((param->vectors->dir->y * param->sprite_data->spritex)
		- (param->vectors->dir->x * param->sprite_data->spritey));
		param->sprite_data->transy = param->sprite_data->invdet
		* ((-param->vectors->plane->y * param->sprite_data->spritex)
		+ (param->vectors->plane->x * param->sprite_data->spritey));
		param->sprite_data->spscreenx = (int)
		((param->settings->window_size_x / 2)
		* (1 + (param->sprite_data->transx / param->sprite_data->transy)));
		ft_spr_dim(param);
		ft_spr_to_frame(param, param->i);
		param->i++;
	}
}
