/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:56:29 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/23 13:28:48 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void	ft_dda(t_param *param)
{
	param->wall_data->hit = 0;
	while (param->wall_data->hit == 0)
	{
		if (param->wall_data->sidedist.x < param->wall_data->sidedist.y)
		{
			param->wall_data->sidedist.x += param->wall_data->deltadist.x;
			param->wall_data->mapx += param->wall_data->stepx;
			param->wall_data->side = 0;
		}
		else
		{
			param->wall_data->sidedist.y += param->wall_data->deltadist.y;
			param->wall_data->mapy += param->wall_data->stepy;
			param->wall_data->side = 1;
		}
		if (param->map[param->wall_data->mapy][param->wall_data->mapx] == '1')
			param->wall_data->hit = 1;
	}
}

void	ft_step(t_param *param)
{
	if (param->wall_data->raydir.x < 0)
	{
		param->wall_data->stepx = -1;
		param->wall_data->sidedist.x = (param->vectors->pos->x -
			param->wall_data->mapx) * param->wall_data->deltadist.x;
	}
	else
	{
		param->wall_data->stepx = 1;
		param->wall_data->sidedist.x = (param->wall_data->mapx
			+ 1.0 - param->vectors->pos->x) * param->wall_data->deltadist.x;
	}
	if (param->wall_data->raydir.y < 0)
	{
		param->wall_data->stepy = -1;
		param->wall_data->sidedist.y = (param->vectors->pos->y -
			param->wall_data->mapy) * param->wall_data->deltadist.y;
	}
	else
	{
		param->wall_data->stepy = 1;
		param->wall_data->sidedist.y = (param->wall_data->mapy
		+ 1.0 - param->vectors->pos->y) * param->wall_data->deltadist.y;
	}
}

void	ft_deltadist(t_wall_data *data)
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
	if (param->wall_data->side == 0)
	{
		if (param->wall_data->raydir.x < 0)
			return (param->texture->texture1);
		else
			return (param->texture->texture3);
	}
	if (param->wall_data->side == 1)
	{
		if (param->wall_data->raydir.y < 0)
			return (param->texture->texture2);
		else
			return (param->texture->texture4);
	}
	return (NULL);
}

void	ft_img_wall(t_param *param)
{
	param->common_data->iterator_x = 0;
	while (param->common_data->iterator_x < param->settings->window_size_x)
	{
		param->wall_data->camerax = ((2 * param->common_data->iterator_x) /
								(double)param->settings->window_size_x) - 1;
		param->wall_data->raydir.x = param->vectors->dir->x +
			(param->vectors->plane->x * param->wall_data->camerax);
		param->wall_data->raydir.y = param->vectors->dir->y +
			(param->vectors->plane->y * param->wall_data->camerax);
		param->wall_data->mapx = (int)param->vectors->pos->x;
		param->wall_data->mapy = (int)param->vectors->pos->y;
		ft_deltadist(param->wall_data);
		ft_step(param);
		ft_dda(param);
		ft_calc_column(param);
		param->wall_data->txt = ft_txt_select(param);
		ft_fill_column(param);
		param->sprite_data->zbuffer[param->common_data->iterator_x] =
			param->wall_data->walldist;
		param->common_data->iterator_x++;
	}
}
