/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_wall_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:30:45 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/17 10:32:24 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void	ft_fill_px(t_param *param)
{
	wl_data->txtpos = (wl_data->ystart - winY / 2 + wl_data->lineh / 2)
						* wl_data->step;
	while (wl_data->ystart < wl_data->yend)
	{
		txtY = (int)wl_data->txtpos;
		trgb = ft_get_txtcolor(wl_data->txt->txt_data, txtX, txtY);
		ft_img_pixel_put(param->img, i_x, wl_data->ystart, trgb);
		wl_data->txtpos += wl_data->step;
		wl_data->ystart++;
	}
}

void	ft_fill_column(t_param *param)
{
	if (wl_data->side == 0)
		wl_data->wallX = posY + (wl_data->walldist * wl_data->raydir.y);
	else
		wl_data->wallX = posX + (wl_data->walldist * wl_data->raydir.x);
	wl_data->wallX -= floor((wl_data->wallX));
	txtX = (int)(wl_data->wallX * (double)wl_data->txt->texture_Width);
	if (wl_data->side == 0 && wl_data->raydir.x > 0)
		txtX = wl_data->txt->texture_Width - txtX - 1;
	if (wl_data->side == 1 && wl_data->raydir.y < 0)
		txtX = wl_data->txt->texture_Width - txtX - 1;
	wl_data->step = (1.0 * wl_data->txt->texture_High) / wl_data->lineh;
	ft_fill_px(param);
}

void	ft_calc_column(t_param *param)
{
	if (wl_data->side == 0)
		wl_data->walldist = (wl_data->mapx - posX +
			((1 - wl_data->stepx) / 2)) / wl_data->raydir.x;
	else
		wl_data->walldist = (wl_data->mapy - posY +
			((1 - wl_data->stepy) / 2)) / wl_data->raydir.y;
	wl_data->lineh = (int)(winY / wl_data->walldist);
	wl_data->ystart = (-wl_data->lineh / 2) + (winY / 2);
	if (wl_data->ystart < 0)
		wl_data->ystart = 0;
	wl_data->yend = (wl_data->lineh / 2) + (winY / 2);
	if (wl_data->yend >= winY)
		wl_data->yend = winY - 1;
}
