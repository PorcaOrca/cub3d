/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:11:54 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/16 09:48:35 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_spr_pxl(t_param *param, int i)
{
	sp_data->d = (i_y * 256) - (winY * 128) + (sp_data->spriteH * 128);
	txtY = ((sp_data->d
			* sp_data->sp_arr[sp_data->order[i]].s_txt->texture_High)
			/ sp_data->spriteH) / 256;
	if (txtY < 0)
		txtY = -txtY;
	if (txtX < 0)
		txtX = -txtX;
	trgb = ft_get_txtcolor(sp_data->sp_arr[sp_data->order[i]].s_txt->txt_data,
							txtX, txtY);
	if (trgb != 0x00000000)
		ft_img_pixel_put(param->img, sp_data->stripe, i_y, trgb);
}

void		ft_spr_to_frame(t_param *param, int i)
{
	sp_data->stripe = sp_data->spstartX;
	while (sp_data->stripe < sp_data->spendX)
	{
		txtX = (int)(256 * (sp_data->stripe -
				(-sp_data->spriteW / 2 + sp_data->spscreenX))
				* sp_data->sp_arr[sp_data->order[i]].s_txt->texture_Width
				/ sp_data->spriteW) / 256;
		if (sp_data->transY > 0 &&
			sp_data->stripe > 0 &&
			sp_data->stripe < winX &&
			sp_data->transY < sp_data->zbuffer[sp_data->stripe])
		{
			i_y = sp_data->spstartY;
			while (i_y < sp_data->spendY)
			{
				ft_spr_pxl(param, i);
				i_y++;
			}
		}
		sp_data->stripe++;
	}
}

void	ft_spr_dim(t_param *param)
{
	sp_data->spriteH = (int)(winY / sp_data->transY);
	if (sp_data->spriteH < 0)
		sp_data->spriteH = -sp_data->spriteH;
	sp_data->spstartY = -sp_data->spriteH / 2 + winY / 2;
	if (sp_data->spstartY < 0)
		sp_data->spstartY = 0;
	sp_data->spendY = sp_data->spriteH / 2 + winY / 2;
	if (sp_data->spendY >= winY)
		sp_data->spendY = winY - 1;
	sp_data->spriteW = (int)(winY / sp_data->transY);
	if (sp_data->spriteW < 0)
		sp_data->spriteW = - sp_data->spriteW;
	sp_data->spstartX = -sp_data->spriteW / 2 + sp_data->spscreenX;
	if (sp_data->spstartX < 0)
		sp_data->spstartX = 0;
	sp_data->spendX = sp_data->spriteW / 2 + sp_data->spscreenX;
	if (sp_data->spendX >= winX)
		sp_data->spendX = winX - 1;
}

void	ft_sprite_order(t_param *param)
{
	int		i;

	i = 0;
	while (i < param->sprite_num)
	{
		sp_data->order[i] = i;
		sp_data->dist[i] = ((posX - sp_data->sp_arr[i].s_pos_x)
							* (posX - sp_data->sp_arr[i].s_pos_x)
							+ (posY - sp_data->sp_arr[i].s_pos_y)
							* (posY - sp_data->sp_arr[i].s_pos_y));
		i++;
	}
	ft_sprite_sort(sp_data->order, sp_data->dist, param->sprite_num);
}

void	ft_sprite(t_param *param)
{
	int		i;

	i = 0;
	ft_sprite_order(param);
	while (i < param->sprite_num)
	{
		sp_data->spriteX = sp_data->sp_arr[sp_data->order[i]].s_pos_x - posX;
		sp_data->spriteY = sp_data->sp_arr[sp_data->order[i]].s_pos_y - posY;
		sp_data->invdet = 1 / ((planeX * dirY) - (dirX * planeY));
		sp_data->transX = sp_data->invdet
				* ((dirY * sp_data->spriteX) - (dirX * sp_data->spriteY));
		sp_data->transY = sp_data->invdet
				* ((-planeY * sp_data->spriteX) + (planeX * sp_data->spriteY));
		sp_data->spscreenX = (int)((winX / 2)
				* (1 + (sp_data->transX / sp_data->transY)));
		ft_spr_dim(param);
		ft_spr_to_frame(param, i);
		i++;
	}
}
