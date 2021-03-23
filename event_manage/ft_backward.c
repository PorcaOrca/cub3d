/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backward.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:52:41 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/23 11:54:45 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_backward_x(t_param *param, double coll)
{
	if (param->map[(int)(param->vectors->pos->y - coll)]
		[(int)((param->vectors->pos->x -
		(param->vectors->dir->x * param->settings->movement) - coll))]
		!= '1' &&
		param->map[(int)(param->vectors->pos->y + coll)]
		[(int)((param->vectors->pos->x -
		(param->vectors->dir->x * param->settings->movement) + coll))]
		!= '1' &&
		param->map[(int)(param->vectors->pos->y + coll)]
		[(int)((param->vectors->pos->x -
		(param->vectors->dir->x * param->settings->movement) - coll))]
		!= '1' &&
		param->map[(int)(param->vectors->pos->y - coll)]
		[(int)((param->vectors->pos->x -
		(param->vectors->dir->x * param->settings->movement) + coll))]
		!= '1')
		param->vectors->pos->x -= param->vectors->dir->x
		* param->settings->movement;
}

void		ft_backward_y(t_param *param, double coll)
{
	if (param->map[(int)(param->vectors->pos->y -
		(param->vectors->dir->y * param->settings->movement) + coll)]
		[(int)(param->vectors->pos->x + coll)]
		!= '1' &&
		param->map[(int)(param->vectors->pos->y -
		(param->vectors->dir->y * param->settings->movement) - coll)]
		[(int)(param->vectors->pos->x + coll)]
		!= '1' &&
		param->map[(int)(param->vectors->pos->y -
		(param->vectors->dir->y * param->settings->movement) + coll)]
		[(int)(param->vectors->pos->x - coll)]
		!= '1' &&
		param->map[(int)(param->vectors->pos->y -
		(param->vectors->dir->y * param->settings->movement) - coll)]
		[(int)(param->vectors->pos->x - coll)]
		!= '1')
		param->vectors->pos->y -= param->vectors->dir->y
		* param->settings->movement;
}

void		ft_backward(t_param *param, double coll)
{
	ft_backward_x(param, coll);
	ft_backward_y(param, coll);
}
