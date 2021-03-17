/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:56:29 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/17 10:32:30 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void	ft_dda(t_param *param)
{
	wl_data->hit = 0;
	while (wl_data->hit == 0)
	{
		if (wl_data->sidedist.x < wl_data->sidedist.y)
		{
			wl_data->sidedist.x += wl_data->deltadist.x;
			wl_data->mapx += wl_data->stepx;
			wl_data->side = 0;
		}
		else
		{
			wl_data->sidedist.y += wl_data->deltadist.y;
			wl_data->mapy += wl_data->stepy;
			wl_data->side = 1;
		}
		if (Wmap[wl_data->mapy][wl_data->mapx] == '1')
			wl_data->hit = 1;
	}
}

void	ft_step(t_param *param)
{
	if (wl_data->raydir.x < 0)
	{
		wl_data->stepx = -1;
		wl_data->sidedist.x = (posX - wl_data->mapx) * wl_data->deltadist.x;
	}
	else
	{
		wl_data->stepx = 1;
		wl_data->sidedist.x = (wl_data->mapx + 1.0 - posX)
							* wl_data->deltadist.x;
	}
	if (wl_data->raydir.y < 0)
	{
		wl_data->stepy = -1;
		wl_data->sidedist.y = (posY - wl_data->mapy) * wl_data->deltadist.y;
	}
	else
	{
		wl_data->stepy = 1;
		wl_data->sidedist.y = (wl_data->mapy + 1.0 - posY)
							* wl_data->deltadist.y;
	}
}

void	ft_deltadist(t_wl_data *data)
{
	if (data->raydir.y == 0)
		data->deltadist.x = 0;
	else
	{
		if (data->raydir.x == 0)
			data->deltadist.x = 1;
		else
			data->deltadist.x = 1 / data->raydir.x;
	}
	if (data->deltadist.x < 0)
		data->deltadist.x = -data->deltadist.x;
	if (data->raydir.x == 0)
		data->deltadist.y = 0;
	else
	{
		if (data->raydir.y == 0)
			data->deltadist.y = 1;
		else
			data->deltadist.y = 1 / data->raydir.y;
	}
	if (data->deltadist.y < 0)
		data->deltadist.y = -data->deltadist.y;
}

t_txt	*ft_txt_select(t_param *param)
{
	if (wl_data->side == 0)
	{
		if (wl_data->raydir.x < 0)
			return (txt_1);
		else
			return (txt_3);
	}
	if (wl_data->side == 1)
	{
		if (wl_data->raydir.y < 0)
			return (txt_2);
		else
			return (txt_4);
	}
	return (NULL);
}

void	ft_img_wall(t_param *param)
{
	i_x = 0;
	while (i_x < winX)
	{
		wl_data->camerax = ((2 * i_x) / (double)winX) - 1;
		wl_data->raydir.x = dirX + (planeX * wl_data->camerax);
		wl_data->raydir.y = dirY + (planeY * wl_data->camerax);
		wl_data->mapx = (int)posX;
		wl_data->mapy = (int)posY;
		ft_deltadist(wl_data);
		ft_step(param);
		ft_dda(param);
		ft_calc_column(param);
		wl_data->txt = ft_txt_select(param);
		ft_fill_column(param);
		sp_data->zbuffer[i_x] = wl_data->walldist;
		i_x++;
	}
}
