/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forward.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:49:07 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/23 12:07:23 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_forward_x(t_param *param, double coll)
{
	if (param->map[(int)(param->vectors->pos->y - coll)]
		[(int)((param->vectors->pos->x +
		(param->vectors->dir->x * param->settings->movement) - coll))]
		!= '1' &&
		param->map[(int)(param->vectors->pos->y + coll)]
		[(int)((param->vectors->pos->x +
		(param->vectors->dir->x * param->settings->movement) + coll))]
		!= '1' &&
		param->map[(int)(param->vectors->pos->y + coll)]
		[(int)((param->vectors->pos->x +
		(param->vectors->dir->x * param->settings->movement) - coll))]
		!= '1' &&
		param->map[(int)(param->vectors->pos->y - coll)]
		[(int)((param->vectors->pos->x +
		(param->vectors->dir->x * param->settings->movement) + coll))]
		!= '1')
		param->vectors->pos->x += (param->vectors->dir->x
		* param->settings->movement);
}

void		ft_forward_y(t_param *param, double coll)
{
	if (param->map[(int)(param->vectors->pos->y +
		(param->vectors->dir->y * param->settings->movement) - coll)]
		[(int)(param->vectors->pos->x - coll)]
		!= '1' &&
		param->map[(int)(param->vectors->pos->y +
		(param->vectors->dir->y * param->settings->movement) + coll)]
		[(int)(param->vectors->pos->x + coll)]
		!= '1' &&
		param->map[(int)(param->vectors->pos->y +
		(param->vectors->dir->y * param->settings->movement) - coll)]
		[(int)(param->vectors->pos->x + coll)]
		!= '1' &&
		param->map[(int)(param->vectors->pos->y +
		(param->vectors->dir->y * param->settings->movement) + coll)]
		[(int)(param->vectors->pos->x - coll)]
		!= '1')
		param->vectors->pos->y += (param->vectors->dir->y
		* param->settings->movement);
}

void		ft_forward(t_param *param, double coll)
{
	ft_forward_x(param, coll);
	ft_forward_y(param, coll);
}
